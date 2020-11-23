#include "time_lost/objects/item.h"

namespace time_lost{

namespace objects{

Item::Item(types::Position start_pos):
Object(start_pos),
on_field(true),
//TODO: delete can_use
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
    os << "    Position:{y=" << item.pos.y << ", x=" << item.pos.x << "}\n";
    os << "    On field: " << item.on_field << "\n";
    os << "    Can use: " << item.can_use << "\n";
    return os;
}

} // objects
} // time_lost