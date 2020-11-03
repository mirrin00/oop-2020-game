#ifndef FIELD_ITERATOR_CLASS_H
#define FIELD_ITERATOR_CLASS_H

#include "field.h"
#include "../types/time_lost_exception.h"

#include <memory>

namespace time_lost {

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

    types::Position GetCurrentPosition();
};

} // objects
} // time_lost

#endif // FIELD_ITERATOR_CLASS_H