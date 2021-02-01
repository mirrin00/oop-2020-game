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
#include "../objects/sword.h"
#include "../objects/bullets.h"
#include "../objects/first_aid_kit.h"
#include "../objects/field_iterator.h"
#include "../objects/enemy.h"
#include "command.h"
#include "logger.h"
#include "turn_interface.h"
#include "menu.h"
#include <vector>

#include "../logic/saves/time_lost_save.h"

#define STEP_CHANGE 11

namespace time_lost{

namespace logic{

class TimeLost{
protected:
    objects::Player player;

    objects::Field field;
    // FIXME: Replace vector by list
    std::vector<std::shared_ptr<objects::Item>> items;

    std::vector<std::shared_ptr<objects::Enemy>> enemys;

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

    void PlayerInteract();

    void PlayerAttack();

    void AddItem(objects::Item& item);

    void AddItem(objects::Item&& item);

    std::shared_ptr<objects::Item> GetItem(int index);

    std::shared_ptr<objects::Enemy> GetEnemy(int index);

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