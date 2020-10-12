#include "etu_game/objects/object.h"

namespace etu_game{

namespace objects{

Object::Object(int start_h_pos = 0, int start_w_pos = 0):
h_pos(start_h_pos),
w_pos(start_w_pos)
{
}

Object::~Object()
{
}

Object::Object(const Object& obj){
    h_pos = obj.h_pos;
    w_pos = obj.w_pos;
}

Object& Object::operator=(const Object& obj){
    if(this == &obj) return *this;
    h_pos = obj.h_pos;
    w_pos = obj.w_pos;
    return *this;
}

void Object::Notify(){
    pub.Notify<Object>(*this);
}

int Object::GetHeightPosition(){
    return h_pos;
}

int Object::GetWidthPosition(){
    return w_pos;
}

void Object::SetHeightPosition(int new_h_pos){
    h_pos = new_h_pos;
    Notify(); // Logging
}

void Object::SetWidthPosition(int new_w_pos){
    w_pos = new_w_pos;
    Notify(); // Logging
}

std::ostream& operator<<(std::ostream& os, const Object& obj){
    os << "Object:\n";
    os << "    Height position: " << obj.h_pos << "\n";
    os << "    Width position: " << obj.w_pos << "\n";
}

} // objects
} // etu_game