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
#include "rifle.h"
#include "pistol.h"
#include "knife.h"
#include "item.h"
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
    int rifle_bullets, pistol_bullets, first_aid_kits;

    std::shared_ptr<Rifle> rifle;

    std::shared_ptr<Pistol> pistol;

    std::shared_ptr<Knife> knife;

    std::shared_ptr<Weapon> cur_weapon;
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

    std::tuple<int, int, int> Attack();

    void ChangeWeapon(types::WeaponType weapon_type);

    void Reload();

    std::shared_ptr<Weapon> GetWeapon(types::WeaponType weapon_type);

    Player& operator+=(Item& item);

    Player& operator+=(Item&& item);

    logic::saves::PlayerSave SavePlayer();

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
    std::ostream& operator<<(std::ostream& os, const Player& player);

} // objects
} // time_lost

#endif // PLAYER_H