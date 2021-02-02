#include "time_lost/types/last_action.h"

namespace time_lost{
namespace types{
    
std::ostream& operator<<(std::ostream& os, LastAction last_action){
    switch(last_action){
        case LastAction::kNothing:
            os << "Nothing";
            break;
        case LastAction::kAttack:
            os << "Attack";
            break;
        case LastAction::kMove:
            os << "Move";
            break;
        case LastAction::kShoot:
            os << "Shoot";
            break;
        default:
            os << "Unknown";
    }
    return os;
}

} // types
} // time_lost
