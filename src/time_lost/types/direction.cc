#include "time_lost/types/direction.h"

namespace time_lost{
namespace types{
    
std::ostream& operator<<(std::ostream& os, Direction direct){
    switch(direct){
        case Direction::kDown:
            os << "Down";
            break;
        case Direction::kLeft:
            os << "Left";
            break;
        case Direction::kRight:
            os << "Right";
            break;
        case Direction::kUp:
            os << "Up";
            break;
        default:
            os << "Unknown";
    }
    return os;
}

} // types
} // time_lost
