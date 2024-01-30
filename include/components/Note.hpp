#ifndef DD4FAA4B_D20E_4EB2_8B5E_99AC81A1D66F
#define DD4FAA4B_D20E_4EB2_8B5E_99AC81A1D66F
#include "Component.hpp"
#include "ImageComponent.hpp"
#include <filesystem>
#include <vector>
#include <map>


enum NoteId {

    QuarterNote,
    BeamedEighthNotes,
    QuarterRest,
    HalfNote,
    SixteenthNote,
    WholeNote,
    EighthNote

};


const std::map<NoteId, std::filesystem::path> noteImagePath = {
    {NoteId::QuarterNote, "res/notes/quarter-note.png"},
    {NoteId::BeamedEighthNotes, "res/notes/beamed-eighth-notes.png"},
    {NoteId::QuarterRest, "res/notes/quarter-rest.png"},
    {NoteId::HalfNote, "res/notes/half-note.png"},
    {NoteId::SixteenthNote, "res/notes/sixteenth-note.png"},
    {NoteId::WholeNote, "res/notes/whole-note.png"},
    {NoteId::EighthNote, "res/notes/eighth-note.png"}
};


const std::vector<NoteId> allNotesIds = {
    QuarterNote,
    BeamedEighthNotes,
    QuarterRest,
    HalfNote,
    SixteenthNote,
    WholeNote,
    EighthNote
};


class Note : public ImageComponent {

    private:
        NoteId id;        
        bool isActive_ = false;

    public:
        Note(
            const NoteId id
        ) : ImageComponent(noteImagePath.at(id)), 
            id(id) { }
        inline void changeNote(const NoteId id) {
            changeImage(noteImagePath.at(id));
        }        
        inline void setActive(const bool isActive) { isActive_ = isActive; }
        void draw(sf::RenderWindow& window) override {
            scale = isActive_ == true ? sf::Vector2f(1.1f, 1.1f) : sf::Vector2f(1.f, 1.f);
            ImageComponent::draw(window);
        }

};



#endif /* DD4FAA4B_D20E_4EB2_8B5E_99AC81A1D66F */
