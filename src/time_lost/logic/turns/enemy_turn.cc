#include "time_lost/logic/turns/enemy_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

EnemyTurn::EnemyTurn(TimeLost& game):
TurnInterface(game)
{
}

void EnemyTurn::Pause(){}

void EnemyTurn::NextTurn(){
    game.EnemysAct();
    game.SetTurn(std::make_unique<PlayerTurn>(game));
}

types::Turns::Turn EnemyTurn::GetTurn(){
    return types::Turns::kEnemy;
}

} // turns
} // logic
} // time_lost