#ifndef BULLETS_TYPE_H
#define BULLETS_TYPE_H

#include <iostream>

namespace time_lost{

namespace types{

enum class BulletType{
    kRifle,
    kPistol,
};

std::ostream& operator<<(std::ostream& os, BulletType bullet_type);

} // types
} // time_lost

#endif // BULLETS_TYPE_H