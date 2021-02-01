#include "time_lost/objects/first_aid_kit.h"

namespace time_lost{

namespace objects{

FirstAidKit::FirstAidKit(int count, types::Position start_pos):
Item(start_pos),
count(count)
{
}

FirstAidKit::~FirstAidKit(){}

FirstAidKit::FirstAidKit(const FirstAidKit& first_aid_kit): Item(first_aid_kit)
{
    count = first_aid_kit.count;
}

FirstAidKit& FirstAidKit::operator=(const FirstAidKit& first_aid_kit){
    if(&first_aid_kit == this) return *this;
    Item::operator=(first_aid_kit);
    count = first_aid_kit.count;
    return *this;
}

void FirstAidKit::Notify(){
    pub.Notify<FirstAidKit>(*this);
}

int FirstAidKit::GetCount(){
    return count;
}

void FirstAidKit::SetCount(int new_count){
    count = new_count;
}

void FirstAidKit::Use(Player& player){
    player.AddFirstAidKits(count);
    Notify(); // Logging
}

std::shared_ptr<Item> FirstAidKit::CloneItem() const{
    return std::make_shared<FirstAidKit>(*this);
}

std::shared_ptr<logic::saves::FirstAidKitSave> FirstAidKit::SaveFirstAidKit(){
    return std::make_shared<logic::saves::FirstAidKitSave>(pos, count, IsOnField());
}

std::shared_ptr<logic::saves::ItemSaveInterface> FirstAidKit::SaveItem(){
    return std::make_shared<logic::saves::FirstAidKitSave>(pos, count, IsOnField());
}

std::ostream& operator<<(std::ostream& os, const FirstAidKit& hp){
    os << "FirstAidKit:\n";
    os << *((Item*)&hp);
    //os << "    Health change: " << hp.health_change << "\n";
    return os;
}

} // objects
} // time_lost