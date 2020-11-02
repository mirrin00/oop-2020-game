#include "time_lost/objects/cell.h"

namespace time_lost{

namespace objects{

Cell::Cell()
    :type(types::CellType::kEmpty)
{
}

Cell::Cell(const Cell& cell){
    type = cell.type;
}
Cell& Cell::operator=(const Cell& cell){
    if (&cell == this) return *this;
    type = cell.type;
    return *this;
}


Cell::Cell(types::CellType cell_type)
    :type(cell_type)
{
}

types::CellType Cell::GetType() const {
    return type;
}


void Cell::SetType(types::CellType new_type){
    type = new_type;
}

Cell::~Cell(){}

} // namespace objects
} // namespace time_lost
