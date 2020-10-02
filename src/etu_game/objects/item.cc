#include "etu_game/objects/item.h"

namespace etu_game{

namespace objects{

Item::Item(int start_h_pos, int start_w_pos):
h_pos(start_h_pos),
w_pos(start_w_pos),
on_field(true)
{
}

Item::~Item(){}

Item::Item(const Item& item){
    h_pos = item.h_pos;
    w_pos = item.w_pos;
    on_field = item.on_field;
    can_use = item.can_use;
}

Item& Item::operator=(const Item& item){
    h_pos = item.h_pos;
    w_pos = item.w_pos;
    on_field = item.on_field;
    can_use = item.can_use;
    return *this;
}


int Item::GetHeightPosition(){
    return h_pos;
}

int Item::GetWidthPosition(){
    return w_pos;
}

void Item::SetHeightPosition(int new_h_pos){
    h_pos = new_h_pos;
}

void Item::SetWidthPosition(int new_w_pos){
    w_pos = new_w_pos;
}

bool Item::IsOnField(){ return on_field;}

void Item::SetOnField(bool on_field){
    this->on_field = on_field;
}

bool Item::IsCanUse(){ return can_use;}

void Item::SetCanUse(bool can_use){
    this->can_use = can_use;
}

} // objects
} // etu_game