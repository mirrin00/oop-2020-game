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
    if(i == field.height * LOCATION_SIZE) throw types::TimeLostException("No next element");
    j++;
    if(j == field.width * LOCATION_SIZE){
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
    return (i == field.height * LOCATION_SIZE);
}

bool FieldIterator::operator()(){
    return (i == field.height * LOCATION_SIZE);
}

const Cell& FieldIterator::CurrentItem(){
    return field.GetCell({j,i});
}

const Cell& FieldIterator::operator*(){
    return field.GetCell({j,i});
}

types::Position FieldIterator::GetCurrentPosition(){
    return {j,i};
}



} // objects
} // time_lost