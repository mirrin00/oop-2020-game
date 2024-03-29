#include "resources_loader.h"

#include<iostream>

namespace time_lost_gui{

    ResourcesLoader::ResourcesLoader(){
        textures.emplace("grass", LoadTexture("resources/grass.png"));
        textures.emplace("block", LoadTexture("resources/block.png"));
        textures.emplace("start", LoadTexture("resources/start.png"));
        textures.emplace("end", LoadTexture("resources/end.png"));
        textures.emplace("player_up", LoadTexture("resources/player_up.png"));
        textures.emplace("player_down", LoadTexture("resources/player_down.png"));
        textures.emplace("player_left", LoadTexture("resources/player_left.png"));
        textures.emplace("player_right", LoadTexture("resources/player_right.png"));
        textures.emplace("bullets", LoadTexture("resources/bullets.png"));
        textures.emplace("hp", LoadTexture("resources/hp.png"));
        textures.emplace("enemy_walk", LoadTexture("resources/enemy_walk.png"));
        textures.emplace("enemy_wait", LoadTexture("resources/enemy_wait.png"));
        textures.emplace("enemy_fly", LoadTexture("resources/enemy_fly.png"));
        fonts.emplace("cour", LoadFont("resources/cour.ttf"));
        fonts.emplace("menu", LoadFont("resources/quick_hand.ttf"));
    }

    sf::Texture ResourcesLoader::LoadTexture(std::string filename){
        sf::Texture texture;
        if(!texture.loadFromFile(filename.c_str()))
            throw time_lost::types::TimeLostException(std::string
                    ("ResourceLoader: Error, can't open file ") + filename);
        return texture;
    }

    sf::Font ResourcesLoader::LoadFont(std::string filename){
        sf::Font font;
        if(!font.loadFromFile(filename))
            throw time_lost::types::TimeLostException(std::string
                    ("ResourceLoader: Error, can't open file ") + filename);
        return font;
    }

    ResourcesLoader::~ResourcesLoader(){}

    ResourcesLoader& ResourcesLoader::GetInstance(){
        static ResourcesLoader resources;
        return resources;
    }

    sf::Texture& ResourcesLoader::GetTexture(std::string texture_name){
        //if(!textures.count(texture_name)) throw time_lost::types::TimeLostException("Error");
        //std::cout<<"TEXTURES" << textures.size()<<'\n';
        //std::cerr<<"TEXTURES" << textures.size()<<'\n';
        //sf::Texture t(textures[texture_name]);
        return textures[texture_name];
    }

    sf::Font& ResourcesLoader::GetFont(std::string font_name){
        return fonts[font_name];
    }

} // namespace time_lost_gui