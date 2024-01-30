#include "../../include/components/ImageComponent.hpp"


ImageComponent::ImageComponent(
    const std::filesystem::path& source
) : Component("Image-" + source.string()) {
    changeImage(source);
}


void ImageComponent::changeImage(const std::filesystem::path& source) {
    TexturePool::load(&this->sprite, source);    
    size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}



void ImageComponent::draw(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    sprite.setScale(scale);
    window.draw(sprite);
}