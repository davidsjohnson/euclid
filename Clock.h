//
// Created by David Johnson on 4/4/21.
//

#ifndef EUCLIDEAN_RHYTHM_GENERATOR_CLOCK_H
#define EUCLIDEAN_RHYTHM_GENERATOR_CLOCK_H

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>


class Clock : public juce::HighResolutionTimer,
              public juce::ActionBroadcaster
{

public:
    Clock(int tempo, int ppqn);
    ~Clock() override;
    void startClock();
    void stopClock();
    void setTempo(int tempo);
    void setPPQN(int ppqn);

private:
    int interval;
    int tempo;
    int ppqn;
    void setInterval(int interval);
    void  hiResTimerCallback() override;
    static int calcClockInterval(int tempo, int ppqn);
    void sendClockMessage();
};


#endif //EUCLIDEAN_RHYTHM_GENERATOR_CLOCK_H
