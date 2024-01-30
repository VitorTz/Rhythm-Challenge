#include "../../include/components/NoteGrid.hpp"
#include <iostream>


NoteGrid::NoteGrid(

) : Component("NoteGrid") {

    for (std::size_t i = 0; i < this->numNotes; i++) {        
        notes.push_back(std::make_unique<Note>(NoteId::QuarterNote));
        this->nextNotes.push_back(this->getRandomNoteId());
    }

    sf::Vector2f noteSize = notes[0]->size;    
    sf::Vector2f noteCenter = {noteSize.x / 2, noteSize.y / 2};
    const float notesWidth = (notes.size() * noteSize.x) + ((notes.size() - 1) * this->columnGap);
    float left = (SCREEN_WIDTH - notesWidth) / 2.f;
    const float top = (SCREEN_HEIGHT / 2.f) - noteSize.y / 2;
    
    for (std::unique_ptr<Note>& note : notes) {
        note->changeOrigin(noteCenter);
        note->pos = {left + noteCenter.x, top + noteCenter.y};
        left += note->size.x + this->columnGap;
    }

    this->nextFirstNote = std::make_unique<Note>(this->nextNotes[0]);
    this->nextFirstNote->changeOrigin(noteCenter);
    this->nextFirstNote->setCenter(this->notes[0]->getCenter());
    this->nextFirstNote->pos.y -= noteSize.y + this->columnGap;

    this->playBeep();
    
}


NoteId NoteGrid::getRandomNoteId() const {
    return allNotesIds[randomInt(0, allNotesIds.size()-1)];
}


void NoteGrid::resetNotes() {
    this->currentNoteIndex = 0;
    for (std::size_t i = 0; i < this->numNotes; i++) {
        std::unique_ptr<Note>& note = this->notes[i];
        note->setActive(false);
        note->changeNote(this->nextNotes[i]);
        this->nextNotes[i] = this->getRandomNoteId();
    }
    this->notes[0]->setActive(true);
    this->nextFirstNote->changeNote(this->nextNotes[0]);
}


void NoteGrid::playBeep() {
    SoundEffect* s = this->currentNoteIndex == 0 ? &accentBeep : &normalBeep;
    s->play();
}


void NoteGrid::update() {    
    if (this->timer.check()) {
        this->timer.reset();
        this->notes[currentNoteIndex]->setActive(false);
        this->currentNoteIndex++;
        if (this->currentNoteIndex >= this->notes.size()) {
            resetNotes();
        }
        this->notes[this->currentNoteIndex]->setActive(true);
        this->playBeep();
    }
}


void NoteGrid::changeTempo(const std::size_t tempo) {
    this->timer.changeDelay(60.f / tempo);
}


void NoteGrid::draw(sf::RenderWindow& window) {
    for (std::unique_ptr<Note>& note : notes) {
        note->draw(window);
    }
    this->nextFirstNote->draw(window);
}