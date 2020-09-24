#ifndef FIELD_ITERATOR_CLASS_H
#define FIELD_ITERATOR_CLASS_H

#include "field.h"
#include "../types/etu_game_exception.h"

#include <memory>

namespace etu_game {

namespace objects {

class FieldIterator{
private:
    const Field& field;
    int i, j;
public:
    FieldIterator(const Field& f);
    
    void Next();

    void operator++();

    void operator++(int);

    bool IsDone();

    bool operator()();

    const Cell& CurrentItem();

    const Cell& operator*();
};

} // objects
} // etu_game

#endif // FIELD_ITERATOR_CLASS_H