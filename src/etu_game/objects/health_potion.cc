#include "etu_game/objects/health_potion.h"

namespace etu_game{

namespace objects{

HealthPotion::HealthPotion(int h_change, int start_h_pos, int start_w_pos):
health_change(h_change),
Item(start_h_pos, start_w_pos)
{
}

HealthPotion::~HealthPotion(){}

void HealthPotion::Use(Player& player){
    if(IsCanUse()) player.ChangeHealth(health_change);
}

} // objects
} // etu_game