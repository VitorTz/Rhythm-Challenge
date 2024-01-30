#ifndef F79FBB1C_B555_414B_97E6_4B186515D1D9
#define F79FBB1C_B555_414B_97E6_4B186515D1D9
#include <SFML/Graphics.hpp>
#include <memory>
#include "../constants.hpp"
#include "../scene/scenes.hpp"
#include "../globals.hpp"


class Window {


    private:
        sf::RenderWindow window;
        std::unique_ptr<Scene> scene;
        ChangeScene changeScene;

    private:
        void handleInput();
        inline void update() { 
            globals::mousePos = sf::Mouse::getPosition(window);
            scene->update();
        }
        inline void render() {
            window.clear(SCREEN_COLOR);
            scene->draw(window);
            window.display();
        }

    public:
        Window();
        inline void run() {
            while (window.isOpen()) {
                handleInput();
                update();
                render();
            }
        }


};

#endif /* F79FBB1C_B555_414B_97E6_4B186515D1D9 */
