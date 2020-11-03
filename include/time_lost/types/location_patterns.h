#ifndef LOCATION_PATTERNS_H
#define LOCATION_PATTERNS_H

#include <string>

namespace time_lost{

namespace types{

class LocationPatterns{
public:
    static const int count = 8;
    static const std::string patterns[count];

    LocationPatterns() = default;
    ~LocationPatterns() = default;
};

} // types
} // time_lost


#endif // LOCATION_PATTERNS_H