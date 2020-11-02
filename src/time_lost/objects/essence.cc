#include "time_lost/objects/essence.h"

namespace time_lost{

namespace objects{

Essence::Essence(int start_health, types::Position start_pos):
Object(start_pos),
health(start_health)
{
}

Essence::~Essence(){}

void Essence::Notify(){
    pub.Notify<Essence>(*this);
}

void Essence::Move(types::Position move){
    pos.x += move.x;
    if(pos.x < 0) pos.x = 0;
    pos.y += move.y;
    if(pos.y < 0) pos.y = 0;
    Notify();
}

std::ostream& operator<<(std::ostream& os, const Essence& essence){
    os << "Essence:\n";
    os << "    Position:{y=" << essence.pos.y << ", x=" 
                             << essence.pos.x << "}\n";
    os << "    Health: " << essence.health << "\n";
    return os;
}

} // objects
} // time_lost