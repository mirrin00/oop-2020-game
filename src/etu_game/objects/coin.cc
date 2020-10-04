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

int Coin::GetCount(){
    return count;
}

void Coin::Use(Player& player){
    if(IsCanUse()) player.AddCoins(count);
}


} // objects
} // etu_game