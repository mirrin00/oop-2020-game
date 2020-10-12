// FIXME: Need delete
/*#ifndef ITEM_LOGGER_H
#define ITEM_LOGGER_H

#include <iostream>
#include <fstream>

#include "logger.h"
#include "../objects/item.h"
#include "../types/etu_game_exception.h"

namespace etu_game{

namespace logic{

class ItemLogger: public Logger{
private:
    std::ofstream file;

    objects::Item& item;

    bool write_in_std;
public:
    ItemLogger(std::string& file_name, objects::Item& object);

    ~ItemLogger();

    void SetObject(objects::Item& object);

    const objects::Item& GetObject();

    void SetWriteInStd(bool write);

    bool IsWriteInStd();

    void WriteLog();
};

} // logic
} // etu_game


#endif // ITEM_LOGGER_H*/