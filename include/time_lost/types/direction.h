#ifndef DIRECTION_TYPE_H
#define DIRECTION_TYPE_H

#include <iostream>

namespace time_lost{

namespace types{

enum class Direction{
    kUp,
    kDown,
    kLeft,
    kRight,
};

std::ostream& operator<<(std::ostream& os, Direction direct);

} // types
} // time_lost

#endif // DIRECTION_TYPE_H