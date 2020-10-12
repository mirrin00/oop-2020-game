#include "etu_game/objects/item.h"

namespace etu_game{

namespace objects{

Item::Item(int start_h_pos, int start_w_pos):
h_pos(start_h_pos),
w_pos(start_w_pos),
on_field(true),
can_use(false)
{
    Notify(); // Logging
}

Item::~Item(){}

Item::Item(const Item& item){
    h_pos = item.h_pos;
    w_pos = item.w_pos;
    on_field = item.on_field;
    can_use = item.can_use;
    Notify(); // Logging
}

Item& Item::operator=(const Item& item){
    if(&item == this) return *this;
    h_pos = item.h_pos;
    w_pos = item.w_pos;
    on_field = item.on_field;
    can_use = item.can_use;
    Notify(); // Logging
    return *this;
}

void Item::Notify(){
    pub.Notify<Item>(*this);
}

int Item::GetHeightPosition(){
    return h_pos;
}

int Item::GetWidthPosition(){
    return w_pos;
}

void Item::SetHeightPosition(int new_h_pos){
    h_pos = new_h_pos;
    Notify(); // Logging
}

void Item::SetWidthPosition(int new_w_pos){
    w_pos = new_w_pos;
    Notify(); // Logging
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

void Item::Subscribe(logic::Subscriber& sub){
    pub.Subscribe(sub);
}

void Item::Unsubscribe(logic::Subscriber& sub){
    pub.Unsubscribe(sub);
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