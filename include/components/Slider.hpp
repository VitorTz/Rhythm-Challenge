#ifndef ED94E5CD_7871_4302_A678_8B6252477000
#define ED94E5CD_7871_4302_A678_8B6252477000
#include "ImageComponent.hpp"
#include "Text.hpp"
#include "../globals.hpp"


typedef struct Range {
    const int start = 0;
    const int end;    
} Range;


enum SliderState {
    Idle,
    Moving
};


class Slider : public Component {

    private:
        ImageComponent circle = ImageComponent("res/slider/slider_circle.png");
        ImageComponent line = ImageComponent("res/slider/slider_line.png");
        Text text = Text(20, sf::Color(158, 250, 250));
        const Range range;
        const sf::Vector2f centerPos;
        SliderState state = SliderState::Idle;
        float progress;
        float rangeProgress;
    
    private:
        void handleMouse();

    public:
        Slider(
            const Range range,
            const sf::Vector2f centerPos,
            const int progress
        );      
        void update() override;
        void draw(sf::RenderWindow& window) override;
        inline float getProgress() { return progress; }
        inline float getRangeProgress() { return rangeProgress; }

};

#endif /* ED94E5CD_7871_4302_A678_8B6252477000 */
