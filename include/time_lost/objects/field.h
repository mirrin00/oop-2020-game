#ifndef FIELD_CLASS_H
#define FIELD_CLASS_H

#include "cell.h"
#include "location.h"
#include "../types/position.h"
#include "../types/time_lost_exception.h"
#include "../logic/publisher.h"

namespace time_lost{
namespace logic{
namespace saves{
class FieldSave;
}
}
}

#include "../logic/saves/field_save.h"

#include <iostream>
#include <memory>

namespace time_lost {

namespace objects {
class Field{
private:
    int height, width;

    std::unique_ptr<Location[]> locs;
    
    std::unique_ptr<std::unique_ptr<int[]>[]> old_layout, new_layout;
    
    // TODO: Implement LoggingInterface, don't forget pub.Notify()
public:
    Field(int height, int width);
    //copy
    Field(const Field& field);
    //oper copy
    Field& operator=(const Field& field);
    //move
    Field(Field&& field);
    //oper move
    Field& operator=(Field&& field);

    ~Field();

    int GetWidth() const;

    int GetHeight() const;

    Cell& GetCell(types::Position pos) const;

    void GenerateField();

    void ChangeLayout();

    types::Position GetNewPosition(types::Position pos);

    logic::saves::FieldSave SaveField();

    
    friend class FieldIterator;

    friend class logic::saves::FieldSave;

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

    std::ostream& operator<<(std::ostream& os, const Field& field);

} // objects
} // time_lost

#endif // FIELD_CLASS_H