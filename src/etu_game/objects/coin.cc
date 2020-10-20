#include "etu_game/objects/coin.h"

namespace etu_game{

namespace objects{

Coin::Coin(int _count, int start_h_pos, int start_w_pos):
count(_count),
Item(start_h_pos, start_w_pos)
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

std::shared_ptr<Item> Coin::clone(){
    return std::make_unique<Coin>(*this);
}

std::ostream& operator<<(std::ostream& os, const Coin& coin){
    os << "Coin:\n";
    os << *((Item*)&coin);
    os << "    Count: " << coin.count << "\n";
    return os;
}

} // objects
} // etu_game