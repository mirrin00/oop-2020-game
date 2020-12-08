#include "time_lost/logic/save_writer.h"

#include "time_lost/types/time_lost_file_exception.h"

namespace time_lost{

namespace logic{

SaveWriter::SaveWriter(std::string filename){
    file.open(filename, std::ofstream::binary);
    if(!file.is_open()) throw types::TimeLostFileException(
                    std::string("Save Writer Error: Can't open file ") + filename);
}

SaveWriter::~SaveWriter(){
    file.close();
}

void SaveWriter::WriteSave(saves::TimeLostSave save){
    file << save;
}

} // logic
} // time_lost