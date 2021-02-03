#ifndef TIME_LOST_H
#define TIME_LOST_H

namespace time_lost{
namespace logic{
class Command;
class TurnInterface;
namespace saves{
class TimeLostSave;
}
}
}

#include "../objects/player.h"
#include "../objects/bullets.h"
#include "../objects/first_aid_kit.h"
#include "../objects/field_iterator.h"
#include "../objects/enemy.h"
#include "command.h"
#include "logger.h"
#include "turn_interface.h"
#include "menu.h"
#include "../types/behavior_find.h"
#include "../types/behavior_wait.h"
#include "../types/behavior_fly.h"
#include "../objects/enemy_type.h"
#include <list>

#include "../logic/saves/time_lost_save.h"

#define STEP_CHANGE 11

namespace time_lost{

namespace logic{

class TimeLost{
protected:
    objects::Player player;

    objects::Field field;
    
    std::list<std::shared_ptr<objects::Item>> items;

    std::list<std::shared_ptr<objects::Enemy>> enemys;

    int step_change;

    std::unique_ptr<TurnInterface> turn;

    Menu menu;
public:
    TimeLost(int height, int width);

    TimeLost(const TimeLost& time_lost);

    TimeLost& operator=(const TimeLost& time_lost);

    ~TimeLost();

    objects::Field& GetField();

    objects::Player& GetPlayer();

    types::Turns::Turn GetTurn();

    void PlayerMove(types::Position move);

    void PlayerChangeDirection(types::Direction direct);

    void PlayerInteract();

    void PlayerAttack();

    void PlayerChangeWeapon(types::WeaponType weapon);

    void PlayerReload();

    void AddItem(objects::Item& item);

    void AddItem(objects::Item&& item);

    std::list<std::shared_ptr<objects::Item>>::const_iterator GetItemIteratorBegin();

    std::list<std::shared_ptr<objects::Item>>::const_iterator GetItemIteratorEnd();

    std::list<std::shared_ptr<objects::Enemy>>::const_iterator GetEnemyIteratorBegin();

    std::list<std::shared_ptr<objects::Enemy>>::const_iterator GetEnemyIteratorEnd();

    void Start();

    void Win();

    void Lose();

    void ExecuteCommand(Command&& cmd);

    void ExecuteCommand(Command& cmd);

    void EnemysAct();

    void SetTurn(std::unique_ptr<TurnInterface> new_turn);

    void Pause();

    void NextTurn();

    bool IsPause();

    void Save();

    void Load();

    void MenuUp();

    void MenuDown();

    void MenuExecute();

    const Menu& GetMenu();

    friend logic::saves::TimeLostSave;
};

} // logic
} // time_lost


#endif // TIME_LOST_H