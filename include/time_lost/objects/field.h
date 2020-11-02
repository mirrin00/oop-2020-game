#ifndef FIELD_CLASS_H
#define FIELD_CLASS_H

#include "cell.h"
#include "../types/position.h"
#include "../types/time_lost_exception.h"
#include "../logic/publisher.h"

#include <iostream>
#include <memory>

namespace time_lost {

namespace objects {
class Field{
private:
    logic::Publisher pub;

    int height, width;
    std::unique_ptr<std::unique_ptr<Cell[]>[]> cells;
    Field(int height, int width);

    //copy
    Field(const Field& field);
    //oper copy
    Field& operator=(const Field& field);
    //move
    Field(Field&& field);
    //oper move
    Field& operator=(Field&& field);
    
    // TODO: method for changing field(don't forget pub.Notify())
public:

    ~Field();

    static Field& GetInstance(int height, int width);

    int GetWidth() const;

    int GetHeight() const;

    Cell& GetCell(types::Position pos);

    // TODO: loading cells-map from some class called "Map"


    bool CheckInvariant();
    
    friend class FieldIterator;

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

    std::ostream& operator<<(std::ostream& os, const Field& field);

} // objects
} // time_lost

#endif // FIELD_CLASS_H