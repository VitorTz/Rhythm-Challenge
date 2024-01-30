#ifndef E1268DDE_AC38_4BC6_AD79_707E6803FEA0
#define E1268DDE_AC38_4BC6_AD79_707E6803FEA0
#include <vector>
#include "Note.hpp"
#include <SFML/Audio.hpp>
#include "../util/util.hpp"
#include "../util/Timer.hpp"
#include "../constants.hpp"


typedef struct SoundEffect {
    SoundEffect(const std::string& source) {
        buffer.loadFromFile(source);
        sound.setBuffer(buffer);
    }
    sf::SoundBuffer buffer;
    sf::Sound sound;
    void play() {
        sound.play();
    }
} SoundEffect;


class NoteGrid : public Component {

    private:
        std::vector<std::unique_ptr<Note>> notes;
        std::unique_ptr<Note> nextFirstNote;
        std::vector<NoteId> nextNotes;
        const std::size_t numNotes = 4;
        const int columnGap = 20;
        SoundEffect accentBeep{"res/sound/beep1.wav"};
        SoundEffect normalBeep{"res/sound/beep2.wav"};        
        std::size_t currentNoteIndex = 0;
        Timer timer = Timer(1.f);
    
    private:
        NoteId getRandomNoteId() const;
        void resetNotes();
        void playBeep();

    public:
        NoteGrid();
        void changeTempo(const std::size_t tempo);
        void update() override;
        void draw(sf::RenderWindow& window);

};

#endif /* E1268DDE_AC38_4BC6_AD79_707E6803FEA0 */
