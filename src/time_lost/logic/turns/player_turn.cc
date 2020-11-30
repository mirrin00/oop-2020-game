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

types::Turns::Turn PlayerTurn::GetTurn(){
    return types::Turns::kPlayer;
}

} // turns
} // logic
} // time_lost