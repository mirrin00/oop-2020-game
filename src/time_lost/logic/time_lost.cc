#include "time_lost/logic/time_lost.h"

namespace time_lost{

namespace logic{

TimeLost::TimeLost(int height, int width):
player(10),
field(objects::Field::GetInstance(height, width))
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
    types::Position new_pos = player.GetPosition() + move;
    if(new_pos.y >= field.GetHeight()) new_pos.y = field.GetHeight() - 1;
    if(new_pos.y < 0) new_pos.y = 0;
    if(new_pos.x >= field.GetWidth()) new_pos.x = field.GetWidth() - 1;
    if(new_pos.x < 0) new_pos.x = 0;
    if(field.GetCell(new_pos).GetType() != types::CellType::kBlock)
        player.SetPosition(new_pos);
}

void TimeLost::PlayerInteract(){
    types::Position pos = player.GetPosition();
    for(int i = 0; i < items.size(); i++){
        if(items[i]->GetPosition() == pos){
            player+=*(items[i]);
            items[i]->SetOnField(false);
        }
    }
}

void TimeLost::AddItem(objects::Item& item){
    items.push_back(item.CloneItem());
}

void TimeLost::AddItem(objects::Item&& item){
    items.push_back(item.CloneItem());
}

std::shared_ptr<objects::Item> TimeLost::GetItem(int index){
    if(index < 0 || index >= items.size()) return nullptr;
    return items[index];
}

void TimeLost::Start(){
    bool no_start = true;
    for(objects::FieldIterator it(field); !it(); it++){
        if((*it).GetType() == types::CellType::kEntry){
            no_start = false;
            player.SetPosition({it.GetCurrentWidth(), it.GetCurrentHeight()});
        }
    }
    if(no_start) throw types::TimeLostException("No start point on map\n");
}

bool TimeLost::IsWin(){
    if(field.GetCell(player.GetPosition()).GetType() == types::CellType::kExit)
        return true;
    return false;
}

} // logic
} // time_lost