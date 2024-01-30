#ifndef AAE8E201_6D3A_4FB6_BC34_23E20ACCD038
#define AAE8E201_6D3A_4FB6_BC34_23E20ACCD038
#include <SFML/Graphics.hpp>
#include <string>
#include "../globals.hpp"


class Component {

    public:
        const std::string name;
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::Vector2f scale = {1.f, 1.f};
    
    public:
        Component(std::string name_) : name(std::move(name_)) { }
        virtual ~Component() = default;
        virtual void update() { }
        virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
        virtual bool isOnHover() {
            const sf::Vector2i mPos = globals::mousePos;
            return (
                mPos.x >= pos.x && 
                mPos.x <= pos.x + size.x &&
                mPos.y >= pos.y &&
                mPos.y <= pos.y + size.y
            );
        }
        inline sf::Vector2f getCenter() const {
            return {pos.x + size.x / 2, pos.y + size.y / 2};
        }
        inline virtual void setCenter(const sf::Vector2f center) {
            pos.x = center.x - size.x / 2;
            pos.y = center.y - size.y / 2;
        }
        inline virtual void setCenterX(const float x) {
            pos.x = x - size.x / 2;
        }
        inline virtual void setCenterY(const float y) {
            pos.y = y - size.y / 2;
        }
        inline float left() const {
            return pos.x;
        }
        inline float right() const {
            return pos.x + size.x;
        }
        inline float top() const {
            return pos.y;
        }
        inline float bottom() const {
            return pos.y + size.y;
        }



};



#endif /* AAE8E201_6D3A_4FB6_BC34_23E20ACCD038 */
