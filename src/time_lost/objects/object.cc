#include "time_lost/objects/object.h"

namespace time_lost{

namespace objects{

Object::Object(types::Position start_pos):
last_action(types::LastAction::kNothing),
pos(start_pos)
{
    if(pos.x < 0) pos.x = 0;
    if(pos.y < 0) pos.y = 0;
}

Object::~Object()
{
}

Object::Object(const Object& obj){
    pos = obj.pos;
}

Object& Object::operator=(const Object& obj){
    if(this == &obj) return *this;
    pos = obj.pos;
    return *this;
}

void Object::Notify(){
    pub.Notify<Object>(*this);
}

types::Position Object::GetPosition() const{
    return pos;
}

void Object::SetPosition(types::Position new_pos){
    pos = new_pos;
    if(pos.x < 0) pos.x = 0;
    if(pos.y < 0) pos.y = 0;
    Notify();
}

types::LastAction Object::GetLastAction() const{
    return last_action;
}

void Object::SetLastAction(types::LastAction new_last_action){
    last_action = new_last_action;
}

std::ostream& operator<<(std::ostream& os, const Object& obj){
    os << "Object:\n";
    os << "    Position:{y=" << obj.pos.y << ", x=" << obj.pos.x << "}\n";
    return os;
}

} // objects
} // time_lost