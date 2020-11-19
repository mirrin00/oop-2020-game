#include <iostream>
#include "time_lost_gui.h"

int main(){
    time_lost_gui::TimeLostGUI game;
    try{
        game.StartGame();
    }catch(time_lost::types::TimeLostException& e){
        std::cout << "Error: " << e.what() << "\n";
    }
    return 0;
}