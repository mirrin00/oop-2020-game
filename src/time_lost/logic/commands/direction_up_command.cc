#include "time_lost/logic/commands/direction_up_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void DirectionUpCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeDirection(types::Direction::kUp);
    game.NextTurn();
}

bool DirectionUpCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost