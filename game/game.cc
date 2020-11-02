#include <SFML/Graphics.hpp>
#include "time_lost/logic/time_lost.h"
#include "time_lost/objects/field_iterator.h"
#include "time_lost/objects/player.h"

#define SIZE 51

//FIXME: delete using
using namespace time_lost;

int main()
{
    try{
    int size = 10;
    logic::TimeLost game(10,10);
    objects::Player& player = game.GetPlayer();
    objects::Field& field = game.GetField();

    sf::RenderWindow window(sf::VideoMode(size*SIZE, size*SIZE), "TimeLost");

    sf::Texture textures[7];
    textures[0].loadFromFile("grass.png");
    textures[1].loadFromFile("block.png");
    textures[2].loadFromFile("start.png");
    textures[3].loadFromFile("end.png");
    textures[4].loadFromFile("player.png");
    textures[5].loadFromFile("coin.png");
    textures[6].loadFromFile("sword.png");
    sf::Font font;
    font.loadFromFile("cour.ttf");

    field.GetCell({1,1}).SetType(types::CellType::kEntry);
    field.GetCell({9,9}).SetType(types::CellType::kExit);
    for(int i = 0;i < size; i++){
        if(i == 5) continue;
        field.GetCell({i,5}).SetType(types::CellType::kBlock);
    }
    game.AddItem(objects::Sword(10,{6,6}));
    game.AddItem(objects::Coin(3,{0,0}));
    game.AddItem(objects::Coin(7,{7,3}));
    logic::Logger logger("game.log",std::cout);
    logic::Subscriber sub(logger);
    {
        int i = 0;
        std::shared_ptr<objects::Item> item = game.GetItem(i);
        while(item){
            item->Subscribe(sub);
            item->SetCanUse(true);
            i++;
            item = game.GetItem(i);
        }
    }
    player.Subscribe(sub);
    game.Start();
    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if(game.IsWin()) continue;
            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W){
                game.PlayerMove({0,-1});
            }

            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A){
                game.PlayerMove({-1,0});
            }

            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S){
                game.PlayerMove({0,1});
            }

            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D){
                game.PlayerMove({1,0});
            }

            if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::E){
                game.PlayerInteract();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);


            if(game.IsWin()){
                sf::Text text;
                text.setFont(font);
                text.setString("You WIN!!!");
                text.setCharacterSize(36);
                text.setPosition((size/2)*SIZE, (size/2)*SIZE);
                text.setFillColor(sf::Color::Red);
                window.draw(text);
                window.display();
                continue;
            }
        sf::Sprite sprite;
        for(int i = 0; i < field.GetHeight();i++){
            for(int j = 0; j < field.GetWidth();j++){
                objects::Cell& cell = field.GetCell({j,i});
                switch (cell.GetType())
                {
                case types::CellType::kEmpty:
                    sprite.setTexture(textures[0]);
                    break;
                
                case types::CellType::kBlock:
                    sprite.setTexture(textures[1]);
                    break;
                
                case types::CellType::kEntry:
                    sprite.setTexture(textures[2]);
                    break;
                
                case types::CellType::kExit:
                    sprite.setTexture(textures[3]);
                    break;
                }
                sprite.setPosition(j*SIZE, i*SIZE);
                window.draw(sprite);
            }
        }
        int i = 0;
        std::shared_ptr<objects::Item> item = game.GetItem(i);
        while(item){
            if(!item->IsOnField()){
                i++;
                item = game.GetItem(i);
                continue;
            }
            if(dynamic_cast<objects::Sword*>(item.get())){
                sprite.setTexture(textures[6]);
            }
            if(dynamic_cast<objects::Coin*>(item.get())){
                sprite.setTexture(textures[5]);
            }
            sprite.setPosition(item->GetPosition().x*SIZE, item->GetPosition().y*SIZE);
            window.draw(sprite);
            i++;
            item = game.GetItem(i);
        }
        sprite.setTexture(textures[4]);
        sprite.setPosition(player.GetPosition().x*SIZE, player.GetPosition().y*SIZE);
        window.draw(sprite);

        // end the current frame
        window.display();
    }
    }catch(types::TimeLostException& e){
        std::cout<<e.what();
    }catch(std::exception& e){
        std::cout<<e.what()<<"\n";
    }
    return 0;
}