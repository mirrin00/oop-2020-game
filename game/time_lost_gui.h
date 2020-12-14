#ifndef TIME_LOST_GUI_H
#define TIME_LOST_GUI_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <ctime>

#include "time_lost/logic/time_lost.h"
#include "time_lost/logic/player_commands.h"
#include "resources_loader.h"

#define WIDTH_GAME_SIZE 3
#define HEIGHT_GAME_SIZE 3
#define SIZE_TEXTURE 51
#define MAX_TIME 200
#define INFO_BAR_SIZE 30

namespace time_lost_gui{

class TimeLostGUI{
protected:
    std::unique_ptr<time_lost::logic::TimeLost> game;

    ResourcesLoader& resources;

    std::unique_ptr<sf::RenderWindow> window;

    std::unique_ptr<time_lost::logic::Command> cmd;

    void GetCommand();

    void Draw();

    void DrawGame();

    void DrawMenu();

    void DrawPause();

    void DrawWin();

    void DrawLose();

public:
    TimeLostGUI();

    ~TimeLostGUI();

    void StartGame();
};

} // time_lost_gui


#endif // TIME_LOST_GUI_H