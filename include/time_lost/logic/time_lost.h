#ifndef TIME_LOST_H
#define TIME_LOST_H

namespace time_lost{
namespace logic{
class Command;
class TurnInterface;
}
}

#include "../objects/player.h"
#include "../objects/sword.h"
#include "../objects/coin.h"
#include "../objects/health_potion.h"
#include "../objects/field_iterator.h"
#include "../objects/enemy.h"
#include "../objects/enemy_type.h"
#include "command.h"
#include "logger.h"
#include "turn_interface.h"
#include "menu.h"
#include <vector>

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
};

} // logic
} // time_lost


#endif // TIME_LOST_H