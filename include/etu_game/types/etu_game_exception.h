#ifndef ETU_GAME_EXCEPTION_CLASS_H
#define ETU_GAME_EXCEPTION_CLASS_H

#include<string>

namespace etu_game{

namespace types{

class EtuGameException: std::exception{
private:
    int exit_code;
    const char* msg;
public:
    EtuGameException(int code, const char* message);
    ~EtuGameException();
    int GetExitCode();
    const char* what() const noexcept;
};

/* TODO:
 *  What means exit code:
 *    * exception
 *    * group of exceptions ?
 */

} //types
} //etu_game

#endif // ETU_GAME_EXCEPTION_CLASS_H