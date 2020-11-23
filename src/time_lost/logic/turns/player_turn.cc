#include "time_lost/logic/turns/player_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

PlayerTurn::PlayerTurn(TimeLost& game):
TurnInterface(game)
{
}

void PlayerTurn::Pause(){
    game.SetTurn(std::make_unique<PauseTurn>(game));
}

void PlayerTurn::NextTurn(){
    game.SetTurn(std::make_unique<EnemyTurn>(game));
}

bool PlayerTurn::IsPause(){
    return false;
}

bool PlayerTurn::IsPlayerTurn(){
    return true;
}

} // turns
} // logic
} // time_lost