#ifndef PLAYER_ATTACK_COMMAND_H
#define PLAYER_ATTACK_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PlayerAttackCommand: public Command{
public:
    PlayerAttackCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PLAYER_ATTACK_COMMAND_H