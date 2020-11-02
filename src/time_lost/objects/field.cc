#include "time_lost/objects/field.h"

namespace time_lost{

namespace objects {

Field::Field(int height, int width){
    if (height <= 0 || width <= 0) 
        throw types::TimeLostException("Wrong size values for Field");
    this->height = height;
    this->width = width;
    cells = std::make_unique<std::unique_ptr<Cell[]>[]>(height);
    for(int i = 0; i<height; i++){
        cells[i] = std::make_unique<Cell[]>(width);
    }
}

Field::Field(const Field& field){
    height = field.width;
    width = field.height;
    cells = std::make_unique<std::unique_ptr<Cell[]>[]>(height);
    for(int i = 0; i<height; i++){
        cells[i] = std::make_unique<Cell[]>(width);
        for(int j = 0; j<width; j++){
            cells[i][j] = field.cells[i][j];
        }
    }
}

Field& Field::operator=(const Field& field){
    if (&field == this) return *this;
    height = field.height;
    width = field.width;
    cells = std::make_unique<std::unique_ptr<Cell[]>[]>(height);
    for(int i = 0; i<height; i++){
        cells[i] = std::make_unique<Cell[]>(width);
        for(int j = 0; j<width; j++){
            cells[i][j] = field.cells[i][j];
        }
    }
    return *this;
}

Field::Field(Field&& field){
    height = field.height;
    width = field.width;
    cells = std::move(field.cells);
    field.cells = std::unique_ptr<std::unique_ptr<Cell[]>[]>(nullptr);
}

Field& Field::operator=(Field&& field){
    if (&field == this) return *this;
    height = field.height;
    width = field.width;
    cells = std::move(field.cells);
    field.cells = std::unique_ptr<std::unique_ptr<Cell[]>[]>(nullptr);
    return *this;
}

bool Field::CheckInvariant(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if (cells[i][j].GetType() == types::CellType::kBlock) continue;
            if (i < height - 1 && cells[i+1][j].GetType() != types::CellType::kBlock)
                continue;
            if (i > 0 && cells[i-1][j].GetType() != types::CellType::kBlock)
                continue;
            if (j > 0 && cells[i][j-1].GetType() != types::CellType::kBlock)
                continue;
            if (j < width -1 && cells[i][j+1].GetType() != types::CellType::kBlock)
                continue;
            return false;
        }
    }
    return true;
}

Field::~Field(){}

Field& Field::GetInstance(int height, int width){
    static Field field(height, width);
    return field;
}

int Field::GetHeight() const {
    return height;
}

int Field::GetWidth() const {
    return width;
}

Cell& Field::GetCell(types::Position pos){
    return cells[pos.y][pos.x];
}

std::ostream& operator<<(std::ostream& os, const Field& field){
    os << "Field:\n";
    os << "    Height: " << field.height << "\n";
    os << "    Width: " << field.width << "\n";
    os << "    Cells:\n";
    for(int i = 0; i < field.height; i++){
        for(int j = 0; j < field.width; j++)
            os << field.cells[i][j].GetType();
        os << "\n";
    }
    return os;
}

} // objects
} // time_lost