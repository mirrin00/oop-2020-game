#include "time_lost/objects/location.h"
#include <cstdlib>

namespace time_lost{

namespace objects{

Location::Location(const Location& loc){
    for(int i = 0; i < LOCATION_SIZE; i++){
        for(int j = 0; j <LOCATION_SIZE; j++){
            cells[i][j] = loc.cells[i][j];
        }
    }
}

Location& Location::operator=(const Location& loc){
    if(&loc == this) return *this;
    for(int i = 0; i < LOCATION_SIZE; i++){
        for(int j = 0; j <LOCATION_SIZE; j++){
            cells[i][j] = loc.cells[i][j];
        }
    }
    return *this;
}

Cell& Location::GetCell(types::Position pos){
    if(pos.x >= LOCATION_SIZE || pos.x < 0 ||
       pos.y >= LOCATION_SIZE || pos.y < 0) throw types::TimeLostException("Location error: bad position");
    return cells[pos.y][pos.x];
}

Location Location::GenerateLocation(){
    Location loc;
    const std::string pattern = types::LocationPatterns::patterns[rand()
                                % types::LocationPatterns::count];
    int cur_cell = 0;
    for(int i = 0; i < pattern.size(); i++){
        switch(pattern[i]){
            case '#':
                loc.cells[cur_cell/LOCATION_SIZE][cur_cell%LOCATION_SIZE].SetType(types::CellType::kBlock);
                cur_cell++;
                break;
            case '0':
                loc.cells[cur_cell/LOCATION_SIZE][cur_cell%LOCATION_SIZE].SetType(types::CellType::kEmpty);
                cur_cell++;
                break;
        }
        if(cur_cell >= LOCATION_SIZE * LOCATION_SIZE) break;
    }
    return loc;
}

} // objects
} // time_lost