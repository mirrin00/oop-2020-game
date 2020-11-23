#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

namespace time_lost{
namespace objects{
class Item;
}
}

#include "essence.h"
#include "weapon.h"
#include "item.h"
#include "hands.h"
#include "enemy.h"

namespace time_lost {

namespace objects {

class Player: public Essence{
private:
    std::unique_ptr<Weapon> weapon;

    int coins;
protected:
    virtual void Notify() override;
public:
    Player(int start_health, types::Position start_pos = {0,0});

    Player& operator=(const Player& player);

    ~Player();

    void AddCoins(int count);

    int GetCoins();

    void ChangeWeapon(Weapon& new_weapon);

    int Attack();

    Player& operator+=(Item& item);

    Player& operator+=(Item&& item);

    Player& operator+=(Enemy& enemy);

    Player& operator-=(Enemy& enemy);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
    std::ostream& operator<<(std::ostream& os, const Player& player);

} // objects
} // time_lost

#endif // PLAYER_H