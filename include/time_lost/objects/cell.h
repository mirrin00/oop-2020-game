#ifndef CELL_CLASS_H
#define CELL_CLASS_H

#include "../types/cell_type.h"

namespace time_lost{
namespace objects{

class Cell{
private:
    types::CellType type;
public:
    Cell();
    Cell(const Cell& cell);
    Cell& operator=(const Cell& cell);
    Cell(types::CellType);
    ~Cell();
    types::CellType GetType() const;
    void SetType(types::CellType);
};

} // namespace objects
} // namespace time_lost

#endif //CELL_CLASS_H
