#include "time_lost/objects/object.h"

namespace time_lost{

namespace objects{

Object::Object(types::Position start_pos):
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

types::Position Object::GetPosition(){
    return pos;
}

void Object::SetPosition(types::Position new_pos){
    pos = new_pos;
    if(pos.x < 0) pos.x = 0;
    if(pos.y < 0) pos.y = 0;
    Notify();
}

void Object::Subscribe(logic::Subscriber& sub){
    pub.Subscribe(sub);
}

void Object::Unsubscribe(logic::Subscriber& sub){
    pub.Unsubscribe(sub);
}

std::ostream& operator<<(std::ostream& os, const Object& obj){
    os << "Object:\n";
    os << "    Position:{y=" << obj.pos.y << ", x=" << obj.pos.x << "}\n";
    return os;
}

} // objects
} // time_lost