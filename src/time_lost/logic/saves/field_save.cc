#include "time_lost/logic/saves/field_save.h"

namespace time_lost{

namespace logic{

namespace saves{

FieldSave::FieldSave(objects::Field& field):
_width(field.width),
_height(field.height)
{
    _locs = std::make_unique<objects::Location[]>(_width*_height);
    for(int i=0; i < _width*_height; i++)
        _locs[i] = field.locs[i];
    _old_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    _new_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    for(int i = 0; i<_height; i++){
        _old_layout[i] = std::make_unique<int[]>(_width);
        _new_layout[i] = std::make_unique<int[]>(_width);
        for(int j = 0; j<_width; j++){
            _old_layout[i][j] = field.old_layout[i][j];
            _new_layout[i][j] = field.new_layout[i][j];
        }
    }
}

FieldSave::FieldSave(const FieldSave& field){
    _height = field._width;
    _width = field._height;
    _locs = std::make_unique<objects::Location[]>(_width*_height);
    _old_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    _new_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    for(int i = 0; i<_width*_height; i++){
        _locs[i] = field._locs[i];
    }
    for(int i = 0; i<_height; i++){
        _old_layout[i] = std::make_unique<int[]>(_width);
        _new_layout[i] = std::make_unique<int[]>(_width);
        for(int j = 0; j<_width; j++){
            _old_layout[i][j] = field._old_layout[i][j];
            _new_layout[i][j] = field._new_layout[i][j];
        }
    }
}

FieldSave& FieldSave::operator=(const FieldSave& field){
    if(&field == this) return *this;
    _height = field._width;
    _width = field._height;
    _locs = std::make_unique<objects::Location[]>(_width*_height);
    _old_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    _new_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    for(int i = 0; i<_width*_height; i++){
        _locs[i] = field._locs[i];
    }
    for(int i = 0; i<_height; i++){
        _old_layout[i] = std::make_unique<int[]>(_width);
        _new_layout[i] = std::make_unique<int[]>(_width);
        for(int j = 0; j<_width; j++){
            _old_layout[i][j] = field._old_layout[i][j];
            _new_layout[i][j] = field._new_layout[i][j];
        }
    }
    return *this;
}

FieldSave::FieldSave(FieldSave&& field){
    _width = field._width;
    _height = field._height;
    _locs = std::move(field._locs);
    _old_layout = std::move(field._old_layout);
    _new_layout = std::move(field._new_layout);
}

FieldSave& FieldSave::operator=(FieldSave&& field){
    if(&field == this) return *this;
    _width = field._width;
    _height = field._height;
    _locs = std::move(field._locs);
    _old_layout = std::move(field._old_layout);
    _new_layout = std::move(field._new_layout);
    return *this;
}

FieldSave::~FieldSave(){}

objects::Field FieldSave::LoadField(){
    objects::Field field(_height,_width);
    field.locs = std::make_unique<objects::Location[]>(_width*_height);
    for(int i=0; i < _width*_height; i++)
        field.locs[i] = _locs[i];
    field.old_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    field.new_layout = std::make_unique<std::unique_ptr<int[]>[]>(_height);
    for(int i = 0; i<_height; i++){
        field.old_layout[i] = std::make_unique<int[]>(_width);
        field.new_layout[i] = std::make_unique<int[]>(_width);
        for(int j = 0; j<_width; j++){
            field.old_layout[i][j] = _old_layout[i][j];
            field.new_layout[i][j] = _new_layout[i][j];
        }
    }
    return field;
}

std::ostream& operator<<(std::ostream& os, FieldSave& save){
    int type = types::SaveType::kField;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save._width, sizeof(int));
    os.write((char*)&save._height, sizeof(int));
    for(int i = 0; i < save._width*save._height; i++){
        for(int row = 0; row < LOCATION_SIZE; row++){
            for(int col = 0; col < LOCATION_SIZE; col++){
                type = save._locs[i].GetCell({col,row}).GetType();
                os.write((char*)&type, sizeof(int));
            }
        }
    }
    for(int i = 0; i < save._height;i++){
        for(int j=0; j < save._width; j++){
            type = save._new_layout[i][j];
            os.write((char*)&type, sizeof(int));
            type = save._old_layout[i][j];
            os.write((char*)&type, sizeof(int));
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, FieldSave& save){
    int type;
    is.read((char*)&save._width, sizeof(int));
    is.read((char*)&save._height, sizeof(int));
    if(save._height <= 0 || save._width <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    save._locs = std::make_unique<objects::Location[]>(save._width*save._height);
    save._old_layout = std::make_unique<std::unique_ptr<int[]>[]>(save._height);
    save._new_layout = std::make_unique<std::unique_ptr<int[]>[]>(save._height);
    for(int i = 0; i<save._height; i++){
        save._old_layout[i] = std::make_unique<int[]>(save._width);
        save._new_layout[i] = std::make_unique<int[]>(save._width);
    }
    int exit_count = 0;
    for(int i = 0; i < save._width*save._height; i++){
        for(int row = 0; row < LOCATION_SIZE; row++){
            for(int col = 0; col < LOCATION_SIZE; col++){
                is.read((char*)&type, sizeof(int));
                switch(type){
                    case types::CellType::kBlock:
                        save._locs[i].GetCell({col,row}).SetType(types::CellType::kBlock);
                        break;
                    case types::CellType::kEmpty:
                        save._locs[i].GetCell({col,row}).SetType(types::CellType::kEmpty);
                        break;
                    case types::CellType::kEntry:
                        save._locs[i].GetCell({col,row}).SetType(types::CellType::kEntry);
                        break;
                    case types::CellType::kExit:
                        save._locs[i].GetCell({col,row}).SetType(types::CellType::kExit);
                        exit_count++;
                        if(exit_count > 1) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
                        break;
                    default:
                        throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
                }
            }
        }
    }
    int max = save._height * save._width;
    for(int i = 0; i < save._height;i++){
        for(int j=0; j < save._width; j++){
            is.read((char*)&type, sizeof(int));
            if(type >= max || type < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
            save._new_layout[i][j] = type;
            is.read((char*)&type, sizeof(int));
            if(type >= max || type < -1) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
            save._old_layout[i][j] = type;
        }
    }
    return is;
}

} // saves
} // logic
} // time_lost