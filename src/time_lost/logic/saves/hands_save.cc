#include "time_lost/logic/saves/hands_save.h"

namespace time_lost{

namespace logic{

namespace saves{

HandsSave::HandsSave(){}

HandsSave::~HandsSave(){}

objects::Hands HandsSave::LoadHands(){
    return objects::Hands();
}

void HandsSave::WriteWeapon(std::ostream& os){
    os << *this;
}

std::unique_ptr<objects::Weapon> HandsSave::LoadWeapon(){
    return LoadHands().CloneWeapon();
}

std::ostream& operator<<(std::ostream& os, HandsSave& save){
    int type = types::SaveType::kHands;
    os.write((char*)&type, sizeof(int));
    return os;
}

std::istream& operator>>(std::istream& is, HandsSave& save){
    return is;
}


} // saves
} // logic
} // time_lost