//
// Created by David Johnson on 4/10/21.
//

#ifndef EUCLIDEAN_RHYTHM_GENERATOR_TESTCLOCKLISTENER_H
#define EUCLIDEAN_RHYTHM_GENERATOR_TESTCLOCKLISTENER_H

#include <chrono>

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>

class TestClockListener : public juce::ActionListener{

    using TimePoint = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>;

public:
    TestClockListener();
    void actionListenerCallback(const juce::String &message) override;

private:
     TimePoint lastTime;
};


#endif //EUCLIDEAN_RHYTHM_GENERATOR_TESTCLOCKLISTENER_H
