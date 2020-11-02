#ifndef POSITION_H
#define POSITION_H

#include <iostream>

namespace time_lost{

namespace types{

struct Position{
    int x {0};
    int y {0};

    Position(int start_x = 0, int start_y = 0);
};

Position operator+(Position pos1, Position pos2);

Position operator+(Position pos);

Position operator-(Position pos);

Position operator-(Position pos1, Position pos2);

bool operator==(Position pos1, Position pos2);

bool operator!=(Position pos1, Position pos2);

std::ostream& operator<<(std::ostream& os, Position pos);

} // types
} // time_lost

#endif // POSITION_H