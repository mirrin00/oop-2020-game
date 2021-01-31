#include "time_lost/objects/essence.h"

namespace time_lost{

namespace objects{

Essence::Essence(int start_health, types::Position start_pos, Direction direct):
Object(start_pos),
health(start_health),
direct(direct)
{
}

Essence::~Essence(){}

void Essence::Notify(){
    pub.Notify<Essence>(*this);
}

void Essence::SetHealth(int new_health){
    health = new_health;
    Notify(); // Logging
}

void Essence::ChangeHealth(int change_h){
    health += change_h;
    Notify(); // Logging
}

int Essence::GetHealth(){
    return health;
}

void Essence::Move(types::Position move){
    pos.x += move.x;
    if(pos.x < 0) pos.x = 0;
    pos.y += move.y;
    if(pos.y < 0) pos.y = 0;
    Notify();
}

void Essence::SetDirection(Direction new_direct){
    direct = new_direct;
}

Essence::Direction Essence::GetDirection(){
    return direct;
}

void Essence::RotateRight(){
    switch (direct)
    {
    case Up:
        SetDirection(Direction::Right);
        break;
    case Right:
        SetDirection(Direction::Down);
        break;
    case Down:
        SetDirection(Direction::Left);
        break;
    case Left:
        SetDirection(Direction::Up);
        break;
    default:
        SetDirection(Direction::Up);
        break;
    }
}

void Essence::RotateLeft(){
    switch (direct)
    {
    case Up:
        SetDirection(Direction::Left);
        break;
    case Right:
        SetDirection(Direction::Up);
        break;
    case Down:
        SetDirection(Direction::Right);
        break;
    case Left:
        SetDirection(Direction::Down);
        break;
    default:
        SetDirection(Direction::Up);
        break;
    }
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