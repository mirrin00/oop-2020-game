#include "time_lost/logic/saves/bullets_save.h"

namespace time_lost{

namespace logic{

namespace saves{

BulletsSave::BulletsSave(types::Position pos, int count, types::BulletType type, bool on_field):
data{pos, count, type, on_field}
{
}

objects::Bullets BulletsSave::LoadBullets(){
    objects::Bullets Bullets(data.count, data.type, data.pos);
    Bullets.SetOnField(data.on_field);
    return Bullets;
}

std::shared_ptr<objects::Item> BulletsSave::LoadItem(){
    return LoadBullets().CloneItem();
}

void BulletsSave::WriteItem(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, BulletsSave& save){
    int type = types::SaveType::kBullets;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(BulletsSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, BulletsSave& save){
    is.read((char*)&save.data, sizeof(BulletsSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.count <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost