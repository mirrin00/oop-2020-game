#include "time_lost/logic/commands/empty_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void EmptyCommand::Execute(TimeLost& game){}

bool EmptyCommand::IsEmpty(){
    return true;
}

} // commands
} // logic
} // time_lost