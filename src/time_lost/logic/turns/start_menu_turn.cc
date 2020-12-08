#include "time_lost/logic/turns/start_menu_turn.h"

namespace time_lost{

namespace logic{

namespace turns{

StartMenuTurn::StartMenuTurn(TimeLost& game):
TurnInterface(game)
{
}

void StartMenuTurn::Pause(){}

void StartMenuTurn::NextTurn(){}

types::Turns::Turn StartMenuTurn::GetTurn(){
    return types::Turns::kStartMenu;
}

} // turns
} // logic
} // time_lost