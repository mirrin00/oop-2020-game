#include "time_lost/logic/commands/direction_left_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void DirectionLeftCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeDirection(types::Direction::kLeft);
    game.NextTurn();
}

bool DirectionLeftCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost