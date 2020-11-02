#include "time_lost/objects/essence.h"

namespace time_lost{

namespace objects{

Essence::Essence(int start_health, int start_h_pos, int start_w_pos):
Object(start_h_pos, start_w_pos),
health(start_health)
{
}

Essence::~Essence(){}

void Essence::Notify(){
    pub.Notify<Essence>(*this);
}

void Essence::Move(int on_height, int on_width){
    h_pos += on_height;
    w_pos += on_width;
    Notify();
}

std::ostream& operator<<(std::ostream& os, const Essence& essence){
    os << "Essence:\n";
    os << "    Height position: " << essence.h_pos << "\n";
    os << "    Width position: " << essence.w_pos << "\n";
    os << "    Health: " << essence.health << "\n";
    return os;
}

} // objects
} // time_lost