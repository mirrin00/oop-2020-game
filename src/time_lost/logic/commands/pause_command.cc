#include "time_lost/logic/commands/pause_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PauseCommand::Execute(TimeLost& game){
    game.Pause();
}

bool PauseCommand::IsEmpty(){
    return true;
}

} // commands
} // logic
} // time_lost