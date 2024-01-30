#include "../../include/util/TexturePool.hpp"



std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TexturePool::textureMap;



void TexturePool::load(sf::Sprite* sprite, const std::filesystem::path& source) {
    if (TexturePool::textureMap.find(source) == TexturePool::textureMap.end()) {
        const auto& [pair, success] = TexturePool::textureMap.insert(
            {
                source,
                std::make_unique<sf::Texture>()
            }
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(source);
    }
    sprite->setTexture(
        *TexturePool::textureMap.at(source)
    );
}


void TexturePool::erase(const std::filesystem::path& source) {
    TexturePool::textureMap.erase(source);
}