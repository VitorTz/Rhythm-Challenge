#ifndef BA8A66B0_554F_45C7_B94A_838D08AF52B0
#define BA8A66B0_554F_45C7_B94A_838D08AF52B0
#include "Component.hpp"
#include "../util/TexturePool.hpp"


class ImageComponent : public Component {

    protected:
        sf::Sprite sprite;
    
    public:        
        explicit ImageComponent(const std::filesystem::path& source);
        void changeImage(const std::filesystem::path& source);
        virtual void draw(sf::RenderWindow& window) override;
        inline void changeOrigin(const sf::Vector2f origin) {
            this->sprite.setOrigin(origin);
        }

};

#endif /* BA8A66B0_554F_45C7_B94A_838D08AF52B0 */
