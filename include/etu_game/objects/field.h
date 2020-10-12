#ifndef FIELD_CLASS_H
#define FIELD_CLASS_H

#include "cell.h"
#include "../types/etu_game_exception.h"

#include <iostream>
#include <memory>

namespace etu_game {

namespace objects {
class Field{
private:
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
    
    // TODO: method for changing field
public:

    ~Field();

    static Field& GetInstance(int height, int width);

    int GetWidth() const;

    int GetHeight() const;

    // FIXME: may be do through friend for other classes
    const Cell& GetCell(int h_pos, int w_pos);

    // TODO: loading cells-map from some class called "Map"


    bool CheckInvariant();
    
    friend class FieldIterator;

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

    std::ostream& operator<<(std::ostream& os, const Field& field);

} // objects
} // etu_game

#endif // FIELD_CLASS_H