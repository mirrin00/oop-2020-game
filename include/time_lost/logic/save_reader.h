#ifndef SAVE_READER_H
#define SAVE_READER_H

#include <string>
#include <fstream>
#include "saves/saves.h"
#include "../types/time_lost_exception.h"

namespace time_lost{

namespace logic{

class SaveReader{
private:
    std::ifstream file;
public:
    SaveReader(std::string filename);

    ~SaveReader();

    saves::TimeLostSave ReadSave();
};

} // logic
} // time_lost


#endif // SAVE_READER_H