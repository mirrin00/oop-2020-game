#include "etu_game/objects/essence.h"

namespace etu_game{

namespace objects{

Essence::Essence(int start_health, int start_h_pos, int start_w_pos):
h_pos(start_h_pos),
w_pos(start_w_pos),
health(start_health)
{
}

Essence::~Essence(){}

void Essence::Move(int on_height, int on_width){
    h_pos += on_height;
    w_pos += on_width;
}


int Essence::GetHeightPosition(){
    return h_pos;
}

int Essence::GetWidthPosition(){
    return w_pos;
}

void Essence::SetHeightPosition(int new_h_pos){
    h_pos = new_h_pos;
}

void Essence::SetWidhtPosition(int new_w_pos){
    w_pos = new_w_pos;
}

std::ostream& operator<<(std::ostream& os, const Essence& essence){
    os << "    Height position: " << essence.h_pos << "\n";
    os << "    Width position: " << essence.w_pos << "\n";
    os << "    Health: " << essence.health << "\n";
    return os;
}

} // objects
} // etu_game