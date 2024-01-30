#ifndef B34C85D2_4882_40BB_9B06_32668B47A7EA
#define B34C85D2_4882_40BB_9B06_32668B47A7EA
#include "Scene.hpp"


class GamePlayScene : public Scene {

    public:
        explicit GamePlayScene(
            const ChangeScene& changeScene
        );
        void update() override;        

};

#endif /* B34C85D2_4882_40BB_9B06_32668B47A7EA */
