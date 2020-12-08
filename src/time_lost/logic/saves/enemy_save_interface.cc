#include "time_lost/logic/saves/enemy_save_interface.h"

namespace time_lost{

namespace logic{

namespace saves{

EnemySave::EnemySave(types::Position pos, int health, types::SaveType::Type type):
_pos(pos),
_health(health),
_type(type)
{
}

types::SaveType::Type EnemySave::GetSaveType(){
    return _type;
}

std::istream& operator>>(std::istream& is, EnemySave& save){
    is.read((char*)&save, sizeof(EnemySave));
    return is;
}

std::ostream& operator<<(std::ostream& os, EnemySave& save){
    int type = save._type;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save, sizeof(EnemySave));
    return os;
}

}
}
}