#ifndef C9B15E94_5B9F_4332_9064_535C1A9C8EB7
#define C9B15E94_5B9F_4332_9064_535C1A9C8EB7
#include <ctime>
#include <chrono>


typedef std::chrono::_V2::system_clock::time_point CurrentTime;


class Timer {

    public:
        inline static CurrentTime getCurrentTime() {
            return std::chrono::system_clock::now();
        }
    
    private:
        CurrentTime startTime;
        std::chrono::duration<double> delay;

    public:
        Timer(
            double delay
        ) : startTime(Timer::getCurrentTime()), delay(delay) { }
        inline void changeDelay(const double delay_) {
            delay = std::chrono::duration<double>(delay_);
        }
        inline bool check() {
            return Timer::getCurrentTime() - startTime >= delay;
        }
        inline void reset() {
            startTime = Timer::getCurrentTime();
        }


};

#endif /* C9B15E94_5B9F_4332_9064_535C1A9C8EB7 */
