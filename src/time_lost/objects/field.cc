#include "time_lost/objects/field.h"
#include <cstdlib>
#include <ctime>

namespace time_lost{

namespace objects {

Field::Field(int height, int width){
    if (height <= 0 || width <= 0) 
        throw types::TimeLostException("Wrong size values for Field");
    this->height = height;
    this->width = width;
    locs = std::make_unique<Location[]>(width*height);
    old_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    new_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    for(int i = 0; i<height; i++){
        old_layout[i] = std::make_unique<int[]>(width);
        new_layout[i] = std::make_unique<int[]>(width);
        for(int j = 0; j<width; j++){
            old_layout[i][j] = new_layout[i][j] = 0;
        }
    }
}

Field::Field(const Field& field){
    height = field.width;
    width = field.height;
    locs = std::make_unique<Location[]>(width*height);
    old_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    new_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    for(int i = 0; i<width*height; i++){
        locs[i] = field.locs[i];
    }
    for(int i = 0; i<height; i++){
        old_layout[i] = std::make_unique<int[]>(width);
        new_layout[i] = std::make_unique<int[]>(width);
        for(int j = 0; j<width; j++){
            old_layout[i][j] = field.old_layout[i][j];
            new_layout[i][j] = field.new_layout[i][j];
        }
    }
}

Field& Field::operator=(const Field& field){
    if (&field == this) return *this;
    height = field.width;
    width = field.height;
    locs = std::make_unique<Location[]>(width*height);
    old_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    new_layout = std::make_unique<std::unique_ptr<int[]>[]>(height);
    for(int i = 0; i<width*height; i++){
        locs[i] = field.locs[i];
    }
    for(int i = 0; i<height; i++){
        old_layout[i] = std::make_unique<int[]>(width);
        new_layout[i] = std::make_unique<int[]>(width);
        for(int j = 0; j<width; j++){
            old_layout[i][j] = field.old_layout[i][j];
            new_layout[i][j] = field.new_layout[i][j];
        }
    }
    return *this;
}

Field::Field(Field&& field){
    height = field.height;
    width = field.width;
    locs = std::move(field.locs);
    old_layout = std::move(field.old_layout);
    new_layout = std::move(field.new_layout);
}

Field& Field::operator=(Field&& field){
    if (&field == this) return *this;
    height = field.height;
    width = field.width;
    locs = std::move(field.locs);
    old_layout = std::move(field.old_layout);
    new_layout = std::move(field.new_layout);
    return *this;
}

Field::~Field(){}

int Field::GetHeight() const {
    return height * LOCATION_SIZE;
}

int Field::GetWidth() const {
    return width * LOCATION_SIZE;
}

Cell& Field::GetCell(types::Position pos) const{
    if(pos.x >= width*LOCATION_SIZE || pos.x < 0 ||
        pos.y >= height*LOCATION_SIZE || pos.y < 0)
         throw types::TimeLostException("Field error: bad position in GetCell");
    int index = new_layout[pos.y/LOCATION_SIZE][pos.x/LOCATION_SIZE];
    return locs[index].GetCell({pos.x%LOCATION_SIZE, pos.y%LOCATION_SIZE});
}

void Field::GenerateField(){
    srand(time(nullptr));
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            old_layout[i][j] = -1;
            new_layout[i][j] = i*width + j;
            locs[i*width + j] = Location::GenerateLocation();
        }
    }
    if(width * height <= 4){
        types::Position start_pos, end_pos;
        int max_w = width * LOCATION_SIZE;
        int max_h = height * LOCATION_SIZE;
        do{
            start_pos = {rand() % max_w, rand() % max_h};
        }while(GetCell(start_pos).GetType() == types::CellType::kBlock);
        do{
            end_pos = {rand() % max_w, rand() % max_h};
        }while(GetCell(start_pos).GetType() == types::CellType::kBlock ||
                end_pos == start_pos);
        GetCell(start_pos).SetType(types::CellType::kEntry);
        GetCell(end_pos).SetType(types::CellType::kExit);
    }else{
        types::Position start_pos, end_pos;
        int max_w = width * LOCATION_SIZE;
        int max_h = height * LOCATION_SIZE;
        do{
            start_pos = {rand() % max_w, rand() % max_h};
        }while(GetCell(start_pos).GetType() == types::CellType::kBlock);
        bool is_far = false;
        do{
            end_pos = {rand() % max_w, rand() % max_h};
            types::Position dist = end_pos - start_pos;
            dist.x = abs(dist.x);
            dist.y = abs(dist.y);
            if(dist.x * dist.x + dist.y * dist.y <= LOCATION_SIZE * LOCATION_SIZE)
                is_far = false;
            else is_far = true;
        }while(!is_far || GetCell(end_pos).GetType() == types::CellType::kBlock
                        || end_pos == start_pos);
        GetCell(start_pos).SetType(types::CellType::kEntry);
        GetCell(end_pos).SetType(types::CellType::kExit);
    }
}

void Field::ChangeLayout(){
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            old_layout[i][j] = new_layout[i][j];
            new_layout[i][j] = -1;
        }
    }
    
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            int new_pos_w = rand() % width;
            int new_pos_h = rand() % height;
            int pos_w = new_pos_w;
            int pos_h = new_pos_h;
            bool is_comp = false;
            do{
                if(new_layout[pos_h][pos_w] == -1){
                    new_layout[pos_h][pos_w] = old_layout[i][j];
                    old_layout[i][j] = pos_h * width + pos_w;
                    is_comp = true;
                    break;
                }
                pos_w++;
                if(pos_w == width){
                    pos_w = 0;
                    pos_h++;
                    if(pos_h == height){
                        pos_h = 0;
                    }
                }
            }while(new_pos_h != pos_h || new_pos_w != pos_w);
            if(!is_comp) throw types::TimeLostException("Field error: ChangeLayout infinity loop");
        }
    }
}

types::Position Field::GetNewPosition(types::Position pos){
    if(pos.x >= width*LOCATION_SIZE || pos.x < 0 ||
        pos.y >= height*LOCATION_SIZE || pos.y < 0)
         throw types::TimeLostException("Field error: bad position in GetNewPosition");
    int index = old_layout[pos.y/LOCATION_SIZE][pos.x/LOCATION_SIZE];
    if(index == -1) return pos;
    return {(index % width) * LOCATION_SIZE + pos.x % LOCATION_SIZE ,
            (index / width) * LOCATION_SIZE + pos.y % LOCATION_SIZE};
}

std::ostream& operator<<(std::ostream& os, const Field& field){
    os << "Field:\n";
    os << "    Height: " << field.height << "\n";
    os << "    Width: " << field.width << "\n";
    os << "    Cells:\n";
    for(int i = 0; i < field.height; i++){
        for(int j = 0; j < field.width; j++)
            os << field.GetCell({j,i}).GetType();
        os << "\n";
    }
    return os;
}

} // objects
} // time_lost