#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class SaveCommand: public Command{
public:
    SaveCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // SAVE_COMMAND_H