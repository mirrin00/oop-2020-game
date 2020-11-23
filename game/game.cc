#include <SFML/Graphics.hpp>
#include "time_lost/logic/time_lost.h"
#include "time_lost/logic/player_commands.h"

#define SIZE 51

//FIXME: delete using
using namespace time_lost;
//using namespace time_lost_gui;

int main()
{
    try{
    logic::TimeLost game(3,3);
    game.Start();
    game.ExecuteCommand(logic::commands::PlayerMoveDownCommand());
    game.ExecuteCommand(logic::commands::PlayerMoveLeftCommand());
    game.ExecuteCommand(logic::commands::PlayerInteractCommand());
    game.ExecuteCommand(logic::commands::PlayerAttackCommand());

    }catch(types::TimeLostException& e){
        std::cout<<e.what();
    }catch(std::exception& e){
        std::cout<<e.what()<<"\n";
    }
    return 0;
}