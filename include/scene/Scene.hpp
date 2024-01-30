#ifndef DFF1163C_7836_4C88_AD8C_D220E7AF9618
#define DFF1163C_7836_4C88_AD8C_D220E7AF9618
#include "../components/components.hpp"
#include <functional>
#include <memory>
#include <string>
#include <map>

enum SceneId {
    GameScene
};

const SceneId mainScene = SceneId::GameScene;


typedef std::function<void(SceneId)> ChangeScene;


class Scene {

    public:
        const SceneId id;
    
    protected:
        std::map<std::string, std::unique_ptr<Component>> componentMap;
        const ChangeScene& changeScene;
    
    protected:
        inline void addComponent(std::unique_ptr<Component> c) {
            this->componentMap.insert({c->name, std::move(c)});
        }
        inline Component* getComponent(const std::string& componentName) {
            return componentMap.at(componentName).get();
        }
    
    public:

        Scene(const SceneId id, const ChangeScene& changeScene) : id(id), changeScene(changeScene) { }
        virtual ~Scene() = default;
        virtual void update() {
            for (const auto& [n, component] : componentMap) 
                component->update();
        }
        virtual void draw(sf::RenderWindow& window) {
            for (const auto& [n, component] : componentMap) 
                component->draw(window);
        }
    
};


#endif /* DFF1163C_7836_4C88_AD8C_D220E7AF9618 */
