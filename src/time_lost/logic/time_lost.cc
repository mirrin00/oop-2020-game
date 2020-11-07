#include "time_lost/logic/time_lost.h"

namespace time_lost{

namespace logic{

TimeLost::TimeLost(int height, int width):
player(10),
field(height, width)
{
}

TimeLost::~TimeLost(){}

objects::Field& TimeLost::GetField(){
    return field;
}

objects::Player& TimeLost::GetPlayer(){
    return player;
}

void TimeLost::PlayerMove(types::Position move){
    if(IsWin()) return;
    types::Position new_pos = player.GetPosition() + move;
    if(new_pos.y >= field.GetHeight()) new_pos.y = field.GetHeight() - 1;
    if(new_pos.y < 0) new_pos.y = 0;
    if(new_pos.x >= field.GetWidth()) new_pos.x = field.GetWidth() - 1;
    if(new_pos.x < 0) new_pos.x = 0;
    if(field.GetCell(new_pos).GetType() != types::CellType::kBlock)
        player.SetPosition(new_pos);
    step_change--;
    if(step_change == 0){
        step_change = STEP_CHANGE;
        field.ChangeLayout();
        player.SetPosition(field.GetNewPosition(player.GetPosition()));
        for(int i = 0; i < items.size(); i++){
            items[i]->SetPosition(field.GetNewPosition(items[i]->GetPosition()));
        }
    }
}

void TimeLost::PlayerInteract(){
    if(IsWin()) return;
    types::Position pos = player.GetPosition();
    for(int i = 0; i < items.size(); i++){
        if(items[i]->GetPosition() == pos){
            player+=*(items[i]);
            items[i]->SetOnField(false);
        }
    }
}

void TimeLost::AddItem(objects::Item& item){
    std::shared_ptr<objects::Item> _item = item.CloneItem();
    types::Position pos = _item->GetPosition();
    while(field.GetCell(pos).GetType() != types::CellType::kEmpty){
        pos.x++;
        if(pos.x == field.GetWidth()){
            pos.x = 0;
            pos.y++;
            if(pos.y == field.GetHeight()){
                pos.y = 0;
            }
        }
    }
    _item->SetPosition(pos);
    items.push_back(_item);
}

void TimeLost::AddItem(objects::Item&& item){
    std::shared_ptr<objects::Item> _item = item.CloneItem();
    types::Position pos = _item->GetPosition();
    while(field.GetCell(pos).GetType() != types::CellType::kEmpty){
        pos.x++;
        if(pos.x == field.GetWidth()){
            pos.x = 0;
            pos.y++;
            if(pos.y == field.GetHeight()){
                pos.y = 0;
            }
        }
    }
    _item->SetPosition(pos);
    items.push_back(_item);
}

std::shared_ptr<objects::Item> TimeLost::GetItem(int index){
    if(index < 0 || index >= items.size()) return nullptr;
    return items[index];
}

void TimeLost::Start(){
    step_change = STEP_CHANGE;
    field.GenerateField();
    bool no_start = true;
    for(objects::FieldIterator it(field); !it(); it++){
        if((*it).GetType() == types::CellType::kEntry){
            no_start = false;
            player.SetPosition(it.GetCurrentPosition());
        }
    }
    if(no_start) throw types::TimeLostException("No start point on map\n");
}

bool TimeLost::IsWin(){
    if(field.GetCell(player.GetPosition()).GetType() == types::CellType::kExit)
        return true;
    return false;
}

void TimeLost::ExecuteCommand(Command& cmd){
    cmd.Execute();
}

void TimeLost::ExecuteCommand(Command&& cmd){
    cmd.Execute();
}

} // logic
} // time_lost