#include "etu_game/objects/field_iterator.h"

namespace etu_game{

namespace objects {

FieldIterator::FieldIterator(const Field& f)
    :field(f),
    i(0),
    j(0)
{
}

void FieldIterator::Next(){
    if(i == field.height) throw types::EtuGameException(1, "No next element");
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
} // etu_game