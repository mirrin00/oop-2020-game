#ifndef PAUSE_COMMAND_H
#define PAUSE_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class PauseCommand: public Command{
public:
    PauseCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // PAUSE_COMMAND_H