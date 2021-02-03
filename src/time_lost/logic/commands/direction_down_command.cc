#include "time_lost/logic/commands/direction_down_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void DirectionDownCommand::Execute(TimeLost& game){
    if(game.GetTurn() != types::Turns::kPlayer) return;
    game.PlayerChangeDirection(types::Direction::kDown);
    game.NextTurn();
}

bool DirectionDownCommand::IsEmpty(){
    return false;
}

} // commands
} // logic
} // time_lost