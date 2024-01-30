#include "../../include/window/Window.hpp"


Window::Window(

) : window(
    sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
    SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    window.setFramerateLimit(FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - SCREEN_WIDTH / 2,
            desktop.height / 2 - SCREEN_HEIGHT / 2
        )
    );

    changeScene = [this](const SceneId id) {
        switch (id) {
            case SceneId::GameScene:
                this->scene = std::make_unique<GamePlayScene>(this->changeScene);
                break;      
            default:
                break;
        }
    };

    changeScene(mainScene);

}


void Window::handleInput() {
    sf::Event e;
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

