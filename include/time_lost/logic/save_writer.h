#ifndef SAVE_WRITER_H
#define SAVE_WRITER_H

#include <string>
#include <fstream>
#include "saves/saves.h"
#include "../types/time_lost_exception.h"

namespace time_lost{

namespace logic{

class SaveWriter{
private:
    std::ofstream file;
public:
    SaveWriter(std::string filename);

    ~SaveWriter();

    void WriteSave(saves::TimeLostSave save);
};

} // logic
} // time_lost


#endif // SAVE_WRITER_H