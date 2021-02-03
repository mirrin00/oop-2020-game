#include "time_lost/logic/commands/direction_right_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void DirectionRightCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeDirection(types::Direction::kRight);
    game.NextTurn();
}

bool DirectionRightCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost