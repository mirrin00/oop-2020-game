#ifndef CELL_TYPE_H
#define CELL_TYPE_H

namespace time_lost{

namespace types{

enum CellType{
    kEmpty = 0,
    kBlock = 1,
    kEntry = 2,
    kExit = 3,
};

} // types
} // time_lost

#endif // CELL_TYPE_H