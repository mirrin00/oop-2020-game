#include "time_lost/logic/saves/enemy_save_interface.h"

namespace time_lost{

namespace logic{

namespace saves{

EnemySave::EnemySave(types::Position pos, int health, types::SaveType::Type type):
data{pos, health, type}
{
}

types::SaveType::Type EnemySave::GetSaveType(){
    return data.type;
}

std::istream& operator>>(std::istream& is, EnemySave& save){
    is.read((char*)&save, sizeof(EnemySave));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.health <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

std::ostream& operator<<(std::ostream& os, EnemySave& save){
    int type = save.data.type;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(EnemySave::Data));
    return os;
}

}
}
}