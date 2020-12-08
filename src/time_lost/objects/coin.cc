#include "time_lost/objects/coin.h"

namespace time_lost{

namespace objects{

Coin::Coin(int _count, types::Position start_pos):
count(_count),
Item(start_pos)
{
}

Coin::~Coin(){}

Coin::Coin(const Coin& coin): Item(coin)
{
    count =  coin.count;
}

Coin& Coin::operator=(const Coin& coin){
    if(&coin == this) return *this;
    Item::operator=(coin);
    count = coin.count;
    return *this;
}

void Coin::Notify(){
    pub.Notify<Coin>(*this);
}

int Coin::GetCount(){
    return count;
}

void Coin::Use(Player& player){
    if(IsCanUse()) player.AddCoins(count);
    SetCanUse(false);
    Notify(); // Logging
}

std::shared_ptr<Item> Coin::CloneItem() const{
    return std::make_shared<Coin>(*this);
}

std::shared_ptr<logic::saves::CoinSave> Coin::SaveCoin(){
    return std::make_shared<logic::saves::CoinSave>(pos, count, IsOnField(), IsCanUse());
}

std::shared_ptr<logic::saves::ItemSaveInterface> Coin::SaveItem(){
    return std::make_shared<logic::saves::CoinSave>(pos, count, IsOnField(), IsCanUse());
}

std::ostream& operator<<(std::ostream& os, const Coin& coin){
    os << "Coin:\n";
    os << *((Item*)&coin);
    os << "    Count: " << coin.count << "\n";
    return os;
}

} // objects
} // time_lost