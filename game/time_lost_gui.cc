#include "time_lost_gui.h"

namespace time_lost_gui{

    TimeLostGUI::TimeLostGUI():
    resources(ResourcesLoader::GetInstance()),
    game(std::make_unique<time_lost::logic::TimeLost>(HEIGHT_GAME_SIZE, WIDTH_GAME_SIZE))
    {
        //FIXME: 13x13 cells
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH_GAME_SIZE*SIZE_TEXTURE*LOCATION_SIZE, HEIGHT_GAME_SIZE*SIZE_TEXTURE*LOCATION_SIZE), "TimeLost");
    }

    TimeLostGUI::~TimeLostGUI(){}

    void TimeLostGUI::draw(){
        window->clear(sf::Color::Black);

        if(game->IsWin()){
            sf::Text text;
            text.setFont(resources.GetFont("cour"));
            text.setString("You WIN!!!");
            text.setCharacterSize(36);
            text.setPosition(500, 500);
            text.setFillColor(sf::Color::Red);
            window->draw(text);
            window->display();
            return;
        }

        sf::Sprite sprite;
        for(time_lost::objects::FieldIterator it(game->GetField()); !it(); it++){
                const time_lost::objects::Cell& cell = *it;
                time_lost::types::Position pos = it.GetCurrentPosition();
                switch (cell.GetType())
                {
                case time_lost::types::CellType::kEmpty:
                    sprite.setTexture(resources.GetTexture("grass"));
                    break;
                
                case time_lost::types::CellType::kBlock:
                    sprite.setTexture(resources.GetTexture("block"));
                    break;
                
                case time_lost::types::CellType::kEntry:
                    sprite.setTexture(resources.GetTexture("start"));
                    break;
                
                case time_lost::types::CellType::kExit:
                    sprite.setTexture(resources.GetTexture("end"));
                    break;
                }
                sprite.setPosition(pos.x*SIZE_TEXTURE, pos.y*SIZE_TEXTURE);
                window->draw(sprite);
        }
        int i = 0;
        std::shared_ptr<time_lost::objects::Item> item = game->GetItem(i);
        while(item){
            if(!item->IsOnField()){
                i++;
                item = game->GetItem(i);
                continue;
            }
            if(dynamic_cast<time_lost::objects::Sword*>(item.get())){
                sprite.setTexture(resources.GetTexture("sword"));
            }
            if(dynamic_cast<time_lost::objects::Coin*>(item.get())){
                sprite.setTexture(resources.GetTexture("bullets"));
            }
            sprite.setPosition(item->GetPosition().x*SIZE_TEXTURE, item->GetPosition().y*SIZE_TEXTURE);
            window->draw(sprite);
            i++;
            item = game->GetItem(i);
        }
        sprite.setTexture(resources.GetTexture("player"));
        sprite.setPosition(game->GetPlayer().GetPosition().x*SIZE_TEXTURE, game->GetPlayer().GetPosition().y*SIZE_TEXTURE);
        window->draw(sprite);

        // end the current frame
        window->display();
    }

    void TimeLostGUI::GetCommand(){
        sf::Event event;
        cmd = std::make_unique<time_lost::logic::commands::EmptyCommand>();
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerMoveUpCommand>();
                }

                if(event.key.code == sf::Keyboard::A){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerMoveLeftCommand>();
                }

                if(event.key.code == sf::Keyboard::S){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerMoveDownCommand>();
                }

                if(event.key.code == sf::Keyboard::D){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerMoveRightCommand>();
                }

                if(event.key.code == sf::Keyboard::E){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerInteractCommand>();
                }
            }
        }
    }

    void TimeLostGUI::StartGame(){
        game->Start();
        while(window->isOpen()){
            GetCommand();
            game->ExecuteCommand(*cmd);
            draw();
        }
    }

} //namespace time_lost_gui
