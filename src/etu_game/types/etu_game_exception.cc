#include "etu_game/types/etu_game_exception.h"

namespace etu_game{

namespace types{

EtuGameException::EtuGameException(int code, const char* message):
exit_code(code),
msg(message)
{
}

EtuGameException::~EtuGameException(){}

int EtuGameException::GetExitCode(){
    return exit_code;
}

const char* EtuGameException::what() const noexcept{
    return msg;
}

} //types
} //etu_game