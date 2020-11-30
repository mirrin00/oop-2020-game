#include "time_lost/logic/turns/lose_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

LoseTurn::LoseTurn(TimeLost& game):
TurnInterface(game)
{
}

void LoseTurn::Pause(){}

void LoseTurn::NextTurn(){}

types::Turns::Turn LoseTurn::GetTurn(){
    return types::Turns::kLose;
}

} // turns
} // logic
} // time_lost