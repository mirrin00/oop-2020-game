#include "time_lost/objects/bullets.h"

namespace time_lost{

namespace objects{

Bullets::Bullets(int _count, types::BulletType _type, types::Position start_pos):
Item(start_pos),
count(_count),
type(_type)
{
}

Bullets::~Bullets(){}

Bullets::Bullets(const Bullets& bullets): Item(bullets)
{
    count =  bullets.count;
    type = bullets.type;
}

Bullets& Bullets::operator=(const Bullets& bullets){
    if(&bullets == this) return *this;
    Item::operator=(bullets);
    count = bullets.count;
    type = bullets.type;
    return *this;
}

void Bullets::Notify(){
    pub.Notify<Bullets>(*this);
}

int Bullets::GetCount(){
    return count;
}

types::BulletType Bullets::GetType(){
    return type;
}

void Bullets::Use(Player& player){
    switch(type){
        case types::BulletType::kPistol:
            player.AddPistolBullets(count);
            break;
        case types::BulletType::kRifle:
            player.AddRifleBullets(count);
            break;
    }
    Notify(); // Logging
}

std::shared_ptr<Item> Bullets::CloneItem() const{
    return std::make_shared<Bullets>(*this);
}

std::shared_ptr<logic::saves::BulletsSave> Bullets::SaveBullets(){
    return std::make_shared<logic::saves::BulletsSave>(pos, count, type, IsOnField());
}

std::shared_ptr<logic::saves::ItemSaveInterface> Bullets::SaveItem(){
    return std::make_shared<logic::saves::BulletsSave>(pos, count, type, IsOnField());
}

std::ostream& operator<<(std::ostream& os, const Bullets& coin){
    os << "Bullets:\n";
    os << *((Item*)&coin);
    os << "    Count: " << coin.count << "\n";
    return os;
}

} // objects
} // time_lost
