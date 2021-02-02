#ifndef LAST_ACTION_H
#define LAST_ACTION_H

#include <iostream>

namespace time_lost{

namespace types{

enum class LastAction{
    kNothing,
    kMove,
    kAttack,
    kShoot,
};

std::ostream& operator<<(std::ostream& os, LastAction& last_action);

} // types
} // time_lost

#endif // LAST_ACTION_H