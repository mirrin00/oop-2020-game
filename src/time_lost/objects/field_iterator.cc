#include "time_lost/objects/field_iterator.h"

namespace time_lost{

namespace objects {

FieldIterator::FieldIterator(const Field& f)
    :field(f),
    i(0),
    j(0)
{
}

void FieldIterator::Next(){
    if(i == field.height) throw types::TimeLostException("No next element");
    j++;
    if(j == field.width){
        j = 0;
        i++;
    }
}

void FieldIterator::operator++(){
    Next();
}

void FieldIterator::operator++(int none){
    Next();
}

bool FieldIterator::IsDone(){
    return (i == field.height);
}

bool FieldIterator::operator()(){
    return (i == field.height);
}

const Cell& FieldIterator::CurrentItem(){
    return field.cells[i][j];
}

const Cell& FieldIterator::operator*(){
    return field.cells[i][j];
}

int FieldIterator::GetCurrentHeight(){
    return i;
}

int FieldIterator::GetCurrentWidth(){
    return j;
}



} // objects
} // time_lost