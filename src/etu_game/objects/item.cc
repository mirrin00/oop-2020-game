#include "etu_game/objects/item.h"

namespace etu_game{

namespace objects{

Item::Item(int start_h_pos, int start_w_pos):
Object(start_h_pos,start_w_pos),
on_field(true),
can_use(false)
{
}

Item::~Item(){}

Item::Item(const Item& item): Object(item){
    on_field = item.on_field;
    can_use = item.can_use;
}

Item& Item::operator=(const Item& item){
    if(&item == this) return *this;
    Object::operator=(item);
    on_field = item.on_field;
    can_use = item.can_use;
    return *this;
}

void Item::Notify(){
    pub.Notify<Item>(*this);
}

bool Item::IsOnField(){ return on_field;}

void Item::SetOnField(bool on_field){
    this->on_field = on_field;
    Notify(); // Logging
}

bool Item::IsCanUse(){ return can_use;}

void Item::SetCanUse(bool can_use){
    this->can_use = can_use;
    Notify(); // Logging
}

std::ostream& operator<<(std::ostream& os, const Item& item){
    os << "    Height position: " << item.h_pos << "\n";
    os << "    Width position: " << item.w_pos << "\n";
    os << "    On field: " << item.on_field << "\n";
    os << "    Can use: " << item.can_use << "\n";
    return os;
}

} // objects
} // etu_game