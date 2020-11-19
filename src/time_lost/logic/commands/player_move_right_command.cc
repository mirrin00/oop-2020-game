#include "time_lost/logic/commands/player_move_right_command.h"

namespace time_lost{

namespace logic{

namespace commands{

void PlayerMoveRightCommand::Execute(TimeLost& game){
    game.PlayerMove({1,0});
}

} // commands
} // logic
} // time_lost