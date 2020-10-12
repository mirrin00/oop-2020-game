// FIXME: Need delete
/*#include "etu_game/logic/item_logger.h"

namespace etu_game{

namespace logic{

ItemLogger::ItemLogger(std::string& file_name, objects::Item& object):
item(object)
{
    file.open(file_name, std::ios_base::app);
    if(!file.is_open()) throw types::EtuGameException(1,
                        (std::string("Can't open file")+file_name).c_str());
}

ItemLogger::~ItemLogger(){
    if(file.is_open()) file.close();
}

void ItemLogger::SetObject(objects::Item& object){
    item = object;
}

const objects::Item& ItemLogger::GetObject(){
    return item;
}

void ItemLogger::SetWriteInStd(bool write){
    write_in_std = write;
}

bool ItemLogger::IsWriteInStd(){
    return write_in_std;
}

void ItemLogger::WriteLog(){
    file << item;
    if(IsWriteInStd()) std::cout << item;
}

}

}*/