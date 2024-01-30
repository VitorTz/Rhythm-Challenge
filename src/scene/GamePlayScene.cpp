#include "../../include/scene/GamePlayScene.hpp"


GamePlayScene::GamePlayScene(
    const ChangeScene& changeScene
) : Scene(SceneId::GameScene, changeScene) {
    this->addComponent(std::make_unique<NoteGrid>());
    this->addComponent(
        std::make_unique<Slider>(Range{20, 260}, sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100), 25)
    );
}


void GamePlayScene::update() {
    Scene::update();
    Slider* slider = (Slider*) this->componentMap.at("Slider").get();
    NoteGrid* noteGrid = (NoteGrid*) this->componentMap.at("NoteGrid").get();
    noteGrid->changeTempo(slider->getRangeProgress());
}