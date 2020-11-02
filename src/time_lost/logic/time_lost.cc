#include "time_lost/logic/time_lost.h"

namespace time_lost{

namespace logic{

TimeLost::TimeLost(int height, int width):
player(10,0,0),
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

void TimeLost::PlayerMove(int h_pos, int w_pos){
    int h = player.GetHeightPosition() + h_pos;
    int w = player.GetWidthPosition() + w_pos;
    if(h < 0 || h >= field.GetHeight()) return;
    if(w < 0 || w >= field.GetWidth()) return;
    if(field.GetCell(h,w).GetType() != types::CellType::kBlock)
        player.Move(h_pos, w_pos);
}

void TimeLost::PlayerInteract(){
    int h_pos = player.GetHeightPosition();
    int w_pos = player.GetWidthPosition();
    for(int i = 0; i < items.size(); i++){
        if(items[i]->GetHeightPosition() == h_pos && items[i]->GetWidthPosition() == w_pos){
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
            player.SetHeightPosition(it.GetCurrentHeight());
            player.SetWidthPosition(it.GetCurrentWidth());
        }
    }
    if(no_start) throw types::TimeLostException("No start point on map\n");
}

bool TimeLost::IsWin(){
    objects::Cell& cell = field.GetCell(player.GetHeightPosition(), player.GetWidthPosition());
    if(cell.GetType() == types::CellType::kExit) return true;
    return false;
}

} // logic
} // time_lost