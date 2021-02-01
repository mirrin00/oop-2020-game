#include "time_lost/logic/saves/first_aid_kit_save.h"

namespace time_lost{

namespace logic{

namespace saves{

FirstAidKitSave::FirstAidKitSave(types::Position pos, int count, bool on_field):
data{pos, count, on_field}
{
}

FirstAidKitSave::~FirstAidKitSave(){}

objects::FirstAidKit FirstAidKitSave::LoadFirstAidKit(){
    objects::FirstAidKit FirstAidKit(data.count, data.pos);
    FirstAidKit.SetOnField(data.on_field);
    return FirstAidKit;
}

std::shared_ptr<objects::Item> FirstAidKitSave::LoadItem(){
    return LoadFirstAidKit().CloneItem();
}

void FirstAidKitSave::WriteItem(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, FirstAidKitSave& save){
    int type = types::SaveType::kFirstAidKit;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(FirstAidKitSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, FirstAidKitSave& save){
    is.read((char*)&save.data, sizeof(FirstAidKitSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.count <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost