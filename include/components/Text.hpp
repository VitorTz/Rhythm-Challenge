#ifndef BE806A49_56A4_47E2_869B_F1047DCE9865
#define BE806A49_56A4_47E2_869B_F1047DCE9865
#include "Component.hpp"


class Text : public Component {

    private:
        sf::Font font;
        sf::Text text;

    public:
        Text(
            const std::string& txt,
            const std::size_t size,
            const sf::Color color
        ) : Component("Text-" + txt) {
            font.loadFromFile("res/font/Roboto/Roboto-Regular.ttf");
            text.setFont(font);
            text.setFillColor(color);
            text.setCharacterSize(size);
            changeTxt(txt);
        }
        Text(            
            const std::size_t size,
            const sf::Color color
        ) : Text("", size, color) { }
        inline void changeTxt(const std::string& txt) {
            text.setString(txt);
            const sf::FloatRect r = text.getLocalBounds();
            size = {r.width, r.height};
        }
        inline void draw(sf::RenderWindow& window) override {
            text.setPosition(pos);
            window.draw(text);
        }

};

#endif /* BE806A49_56A4_47E2_869B_F1047DCE9865 */
