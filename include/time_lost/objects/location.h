#ifndef LOCATION_H
#define LOCATION_H

#include "cell.h"
#include "../types/position.h"
#include "../types/location_patterns.h"
#include "../types/time_lost_exception.h"

#define LOCATION_SIZE 5

namespace time_lost{

namespace objects{

class Location{
private:
    Cell cells[LOCATION_SIZE][LOCATION_SIZE];
public:
    Location() = default;
    
    ~Location() = default;

    Location(const Location& loc);

    Location& operator=(const Location& loc);

    Cell& GetCell(types::Position pos);

    static Location GenerateLocation();
};

} // objects
} // time_lost


#endif // LOCATION_H