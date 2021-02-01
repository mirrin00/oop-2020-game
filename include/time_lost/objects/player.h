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

namespace time_lost{
namespace objects
{
class Enemy;   
}
namespace logic{
namespace saves{
class PlayerSave;
}
}
}

#include "../logic/saves/player_save.h"

namespace time_lost {

namespace objects {

class Player: public Essence{
private:
    std::unique_ptr<Weapon> weapon;

    int rifle_bullets, pistol_bullets, first_aid_kits;
protected:
    virtual void Notify() override;
public:
    Player(int start_health, types::Position start_pos = {0,0}, types::Direction direct = types::Direction::kUp);

    Player(const Player& player);

    Player& operator=(const Player& player);

    ~Player();

    void AddRifleBullets(int bullet_count);

    int GetRifleBullets();

    void AddPistolBullets(int bullet_count);

    int GetPistolBullets();

    void AddFirstAidKits(int first_aid_kit_count);

    int GetFirstAidKits();

    void ChangeWeapon(Weapon& new_weapon);

    int Attack();

    Player& operator+=(Item& item);

    Player& operator+=(Item&& item);

    Player& operator+=(Enemy& enemy);

    Player& operator-=(Enemy& enemy);

    logic::saves::PlayerSave SavePlayer();

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
    std::ostream& operator<<(std::ostream& os, const Player& player);

} // objects
} // time_lost

#endif // PLAYER_H