#ifndef RESOURCES_LOADER_H
#define RESOURCES_LOADER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

#include "time_lost/types/time_lost_exception.h"

namespace time_lost_gui{

class ResourcesLoader{
private:
    std::map<std::string, sf::Texture> textures;

    std::map<std::string, sf::Font> fonts;

    ResourcesLoader();

    sf::Texture LoadTexture(std::string filename);

    sf::Font LoadFont(std::string filename);
public:
    ~ResourcesLoader();

    ResourcesLoader(const ResourcesLoader&) = delete;

    ResourcesLoader(ResourcesLoader&&) = delete;

    static ResourcesLoader& GetInstance();

    sf::Texture& GetTexture(std::string texture_name);

    sf::Font& GetFont(std::string font_name);

    static void Reset();

    // FIXME: add &&
    //sf::Texture GetTexture(std::string&& texture_name);
};

} // time_lost_gui


#endif // RESOURCES_LOADER_H