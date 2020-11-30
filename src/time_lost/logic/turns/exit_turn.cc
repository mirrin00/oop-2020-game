#include "time_lost/logic/turns/exit_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

ExitTurn::ExitTurn(TimeLost& game):
TurnInterface(game)
{
}

void ExitTurn::Pause(){}

void ExitTurn::NextTurn(){}

types::Turns::Turn ExitTurn::GetTurn(){
    return types::Turns::kExit;
}

} // turns
} // logic
} // time_lost