#ifndef FIELD_SAVE_H
#define FIELD_SAVE_H

namespace time_lost{

namespace objects{
class Field;
}
}

#include "../../objects/field.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class FieldSave{
private:
    int _height, _width;

    std::unique_ptr<objects::Location[]> _locs;

    std::unique_ptr<std::unique_ptr<int[]>[]> _old_layout, _new_layout;
public:
    FieldSave() = default;

    FieldSave(objects::Field& field);

    FieldSave(const FieldSave& field);

    FieldSave& operator=(const FieldSave& save);

    FieldSave(FieldSave&& field);

    FieldSave& operator=(FieldSave&& field);

    ~FieldSave();

    objects::Field LoadField();

    friend std::ostream& operator<<(std::ostream& os, FieldSave& save);

    friend std::istream& operator>>(std::istream& is, FieldSave& save);
};

std::ostream& operator<<(std::ostream& os, FieldSave& save);

std::istream& operator>>(std::istream& is, FieldSave& save);

} // saves
} // logic
} // time_lost

#endif // FIELD_SAVE_H