//
// Created by David Johnson on 4/10/21.
//

#include "TestClockListener.h"


TestClockListener::TestClockListener() {
    lastTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
}

void TestClockListener::actionListenerCallback(const juce::String &message) {
    TimePoint recTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    std::cout << "Message Received: "
              << message.toStdString()
              << " " << (recTime - lastTime).count()
              << std::endl;
    lastTime = recTime;
}