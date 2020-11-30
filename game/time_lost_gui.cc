#include "time_lost_gui.h"

//FIXME: delete includes
#include "time_lost/types/behavior_find.h"
#include "time_lost/types/behavior_wait.h"
#include "time_lost/types/behavior_fly.h"

namespace time_lost_gui{

    TimeLostGUI::TimeLostGUI():
    resources(ResourcesLoader::GetInstance()),
    game(std::make_unique<time_lost::logic::TimeLost>(HEIGHT_GAME_SIZE, WIDTH_GAME_SIZE))
    {
        //FIXME: 13x13 cells
        //window = std::make_unique<sf::RenderWindow>(sf::VideoMode(SIZE_TEXTURE*LOCATION_SIZE, SIZE_TEXTURE*LOCATION_SIZE), "TimeLost");
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH_GAME_SIZE*SIZE_TEXTURE*LOCATION_SIZE, HEIGHT_GAME_SIZE*SIZE_TEXTURE*LOCATION_SIZE), "TimeLost");
    }

    TimeLostGUI::~TimeLostGUI(){}

    void TimeLostGUI::DrawGame(){
        window->clear(sf::Color::Black);

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

        i = 0;
        std::shared_ptr<time_lost::objects::Enemy> enemy = game->GetEnemy(i);
        while(enemy){
            if(dynamic_cast<time_lost::objects::EnemyType<time_lost::types::BehaviorFind>*>(enemy.get()))
                sprite.setTexture(resources.GetTexture("enemy_walk"),true);
            if(dynamic_cast<time_lost::objects::EnemyType<time_lost::types::BehaviorWait>*>(enemy.get()))
                sprite.setTexture(resources.GetTexture("enemy_wait"),true);
            if(dynamic_cast<time_lost::objects::EnemyType<time_lost::types::BehaviorFly>*>(enemy.get()))
                sprite.setTexture(resources.GetTexture("enemy_fly"),true);
            sprite.setPosition(enemy->GetPosition().x*SIZE_TEXTURE, enemy->GetPosition().y*SIZE_TEXTURE);
            window->draw(sprite);
            i++;
            enemy = game->GetEnemy(i);
        }

        /* Draw part of field
        sf::View view;
        view.setSize(window->getSize().x, window->getSize().y);
        time_lost::types::Position pos = game->GetPlayer().GetPosition();
        view.setCenter(pos.x*SIZE_TEXTURE+SIZE_TEXTURE/2, pos.y*SIZE_TEXTURE+SIZE_TEXTURE/2);
        window->setView(view);
        */
        // end the current frame
        //window->display();
    }

    void TimeLostGUI::DrawPause(){
        unsigned int h = window->getSize().y, w =window->getSize().x;
        sf::VertexArray quad(sf::Quads, 4);
        quad[0].position = sf::Vector2f(0,h);
        quad[1].position = sf::Vector2f(0,0);
        quad[2].position = sf::Vector2f(w,0);
        quad[3].position = sf::Vector2f(w,h);
        quad[0].color = sf::Color(160,160,160,130);
        quad[1].color = sf::Color(160,160,160,130);
        quad[2].color = sf::Color(160,160,160,130);
        quad[3].color = sf::Color(160,160,160,130);
        window->draw(quad);
        sf::Text text;
        text.setFont(resources.GetFont("cour"));
        text.setString("Pause");
        text.setCharacterSize(48);
        text.setPosition(w/2, h/2);
        text.setFillColor(sf::Color::White);
        window->draw(text);
    }

    void TimeLostGUI::DrawMenu(){
        constexpr int item_size = 75, delta_x = 15;
        auto items = game->GetMenu().GetItems();
        window->clear(sf::Color::Black);
        sf::Text text;
        text.setFont(resources.GetFont("menu"));
        text.setCharacterSize(36);
        unsigned int h = window->getSize().y / 2 - item_size*(items.size()/2), w =window->getSize().x / 2;
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(200,50));
        for(auto item: items){
            text.setString(item->GetDescription());
            if(item->IsSelected()) rect.setFillColor(sf::Color(100,100,100));
            else rect.setFillColor(sf::Color::Black);
            if(!item->GetIsCanExecute()) text.setFillColor(sf::Color(160,160,160));
            else text.setFillColor(sf::Color::White);
            text.setPosition(w - delta_x * ((float)item->GetDescription().size() / 2),h);
            rect.setPosition(text.getPosition());
            window->draw(rect);
            window->draw(text);
            h += item_size;
        }
    }

    void TimeLostGUI::DrawWin(){
        window->clear(sf::Color::Black);
        sf::Text text;
        text.setFont(resources.GetFont("cour"));
        text.setString("YOU WIN!!!");
        text.setCharacterSize(48);
        text.setPosition(150, 150);
        text.setFillColor(sf::Color::Red);
        window->draw(text);
    }

    void TimeLostGUI::DrawLose(){
        window->clear(sf::Color::Black);
        sf::Text text;
        text.setFont(resources.GetFont("cour"));
        text.setString("YOU DIED");
        text.setCharacterSize(48);
        text.setPosition(150, 150);
        text.setFillColor(sf::Color::Red);
        window->draw(text);
    }

    void TimeLostGUI::Draw(){
        switch(game->GetTurn()){
            case time_lost::types::Turns::kStartMenu:
                DrawMenu();
                break;
            case time_lost::types::Turns::kPlayer:
                DrawGame();
                break;
            case time_lost::types::Turns::kPause:
                DrawGame();
                DrawPause();
                break;
            case time_lost::types::Turns::kWin:
                DrawWin();
                break;
            case time_lost::types::Turns::kLose:
                DrawLose();
                break;  
            //default:
                //window->clear(sf::Color::Black);
        }
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

                if(event.key.code == sf::Keyboard::Enter){
                    cmd = std::make_unique<time_lost::logic::commands::PlayerAttackCommand>();
                }

                if(event.key.code == sf::Keyboard::Escape){
                    cmd = std::make_unique<time_lost::logic::commands::PauseCommand>();
                }
            }
        }
    }

    void TimeLostGUI::StartGame(){
        //game->Start();
        // FIXME: DELETE THIS
        
        std::shared_ptr<time_lost::logic::Logger> log = std::make_shared<time_lost::logic::Logger>("game.log", std::cout);
        game->GetPlayer().Subscribe(log);
        //game->GetEnemy(0)->Subscribe(log);
        //
        while(window->isOpen()){
            GetCommand();
            if((dynamic_cast<time_lost::logic::commands::PauseCommand*>(cmd.get()))){
                game->Pause();
                continue;
            }
            game->ExecuteCommand(*cmd);
            Draw();
            if(game->GetTurn() == time_lost::types::Turns::kExit) window->close();
        }
    }

} //namespace time_lost_gui
