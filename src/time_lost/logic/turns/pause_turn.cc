#include "time_lost/logic/turns/pause_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

PauseTurn::PauseTurn(TimeLost& game):
TurnInterface(game)
{
}

void PauseTurn::Pause(){
    game.SetTurn(std::make_unique<PlayerTurn>(game));
}

void PauseTurn::NextTurn(){}

bool PauseTurn::IsPause(){
    return true;
}

bool PauseTurn::IsPlayerTurn(){
    return false;
}

} // turns
} // logic
} // time_lost