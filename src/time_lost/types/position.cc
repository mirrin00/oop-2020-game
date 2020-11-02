#include "time_lost/types/position.h"

namespace time_lost{

namespace types{

Position::Position(int start_x, int start_y):
x(start_x),
y(start_y)
{
}

Position operator+(Position pos1, Position pos2){
    return {pos1.x + pos2.x, pos1.y + pos2.y};
}

Position operator+(Position pos){
    return pos;
}

Position operator-(Position pos1, Position pos2){
    return {pos1.x - pos2.x, pos1.y - pos2.y};
}

Position operator-(Position pos){
    return {-pos.x, -pos.y};
}

bool operator==(Position pos1, Position pos2){
    return (pos1.x == pos2.x && pos1.y == pos2.y);
}

bool operator!=(Position pos1, Position pos2){
    return !(pos1 == pos2);
}

std::ostream& operator<<(std::ostream& os, Position pos){
    os << "Position:{x=" << pos.x << ", y=" << pos.y << "}\n";
    return os;
}

} // types
} // time_lost