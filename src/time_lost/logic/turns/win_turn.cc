#include "time_lost/logic/turns/win_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

WinTurn::WinTurn(TimeLost& game):
TurnInterface(game)
{
}

void WinTurn::Pause(){}

void WinTurn::NextTurn(){}

types::Turns::Turn WinTurn::GetTurn(){
    return types::Turns::kWin;
}

} // turns
} // logic
} // time_lost