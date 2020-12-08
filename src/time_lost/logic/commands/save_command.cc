#include "time_lost/logic/commands/save_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void SaveCommand::Execute(TimeLost& game){
    game.Save();
}

bool SaveCommand::IsEmpty(){
    return true;
}

} // commands
} // logic
} // time_lost