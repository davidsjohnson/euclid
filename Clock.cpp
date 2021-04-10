//
// Created by David Johnson on 4/4/21.
//

#include "Clock.h"

Clock::Clock(int tempo,
             int ppqn) {
    Clock::tempo = tempo;
    Clock::ppqn = ppqn;
    interval = calcClockInterval(tempo, ppqn);
}

Clock::~Clock(){
    stopClock();
}

void Clock::setInterval(int interval) {
    Clock::interval = interval;
    if (isTimerRunning())
        startTimer(interval);
}

void Clock::setPPQN(int ppqn) {
    Clock::ppqn = ppqn;
    setInterval(calcClockInterval(tempo, Clock::ppqn));
}

void Clock::setTempo(int tempo) {
    Clock::tempo = tempo;
    setInterval(calcClockInterval(Clock::tempo, ppqn));
}

int Clock::calcClockInterval(int tempo, int ppqn) {
    return 60 * 1000 / (tempo * ppqn);
}

void Clock::hiResTimerCallback() {
    sendClockMessage();
}

void Clock::sendClockMessage() {
    auto msg = juce::MidiMessage::midiClock();

    for (auto midiOutput : midiOuts)
        if (midiOutput->outDevice.get() != nullptr)
            midiOutput->outDevice->sendMessageNow(msg);

    sendActionMessage("pulse");
}

void Clock::stopClock() {
    stopTimer();
}

void Clock::startClock() {
    startTimer(interval);
    std::cout << "Clock Started: " << interval << std::endl;
}