#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

namespace etu_game{
namespace objects{
class Item;
}
}

#include "essence.h"
#include "weapon.h"
#include "item.h"
#include "hands.h"

namespace etu_game {

namespace objects {

class Player: public Essence{
private:
    std::unique_ptr<Weapon> weapon;

    int coins;
public:
    Player(int start_health, int start_h_pos = 0, int start_w_pos = 0);

    ~Player();

    void ChangeHealth(int change_h);

    int GetHealth();

    void AddCoins(int count);

    int GetCoins();

    void ChangeWeapon(Weapon& new_weapon);

    int Attack();

    /* FIXME:
     *   *  Add for Item&& or Item?
     *   *  What do with operator +
     */
    void operator+=(Item& item);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
    std::ostream& operator<<(std::ostream& os, const Player& player);

} // objects
} // etu_game

#endif // PLAYER_H