#include "../../include/components/Slider.hpp"
#include <iostream>

Slider::Slider(
    const Range range,
    const sf::Vector2f centerPos,
    const int progress
) : Component("Slider"), 
    range(range),
    centerPos(centerPos),
    progress(progress / 100.f) {
    line.setCenter(centerPos);            
    size = {
        line.size.x,
        circle.size.y
    };
    circle.setCenterY(centerPos.y);
    circle.setCenterX(
        line.pos.x + (line.size.x * progress / 100.f)
    );    
    this->rangeProgress = (range.end - range.start) * progress / 100.f + range.start;
    this->text.changeTxt("Tempo: " + std::to_string((int)this->rangeProgress));
    text.setCenterX(centerPos.x);
    text.setCenterY(centerPos.y + 40);
}     


void Slider::handleMouse() {
    float mouseXpos = globals::mousePos.x;
    if (mouseXpos > this->line.right()) {
        mouseXpos = this->line.right();
    } else if (mouseXpos < this->line.left()) {
        mouseXpos = this->line.left();
    }    
    this->progress = (mouseXpos - this->line.pos.x) / this->line.size.x;
    this->rangeProgress = (range.end - range.start) * this->progress + range.start;
    this->circle.setCenterX(mouseXpos);
    this->text.changeTxt("Tempo: " + std::to_string((int)this->rangeProgress));
}


void Slider::update() {
    switch (state) {
        case SliderState::Idle:
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->circle.isOnHover()) {
                state = SliderState::Moving;
            }
            break;
        case SliderState::Moving:
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                state = SliderState::Idle;
            }
            handleMouse();
            break;
        default:
            break;
    }
}


void Slider::draw(sf::RenderWindow& window) {
    line.draw(window);
    circle.draw(window);
    text.draw(window);
}   