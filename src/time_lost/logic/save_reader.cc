#include "time_lost/logic/save_reader.h"

#include "time_lost/types/time_lost_file_exception.h"

namespace time_lost{

namespace logic{

SaveReader::SaveReader(std::string filename){
    file.open(filename, std::ifstream::binary);
    if(!file.is_open()) throw types::TimeLostFileException(
                    std::string("Save Reader Error: Can't open file ") + filename);
}

SaveReader::~SaveReader(){
    file.close();
}

saves::TimeLostSave SaveReader::ReadSave(){
    saves::TimeLostSave save;
    file >> save;
    return save;
}

} // logic
} // time_lost