#pragma once

#include <vector>
#include <JuceHeader.h>

#include "PluginProcessor.h"

class myAudioProcessorEditor  : public AudioProcessorEditor, public Timer
{
public:
    explicit myAudioProcessorEditor (myAudioProcessor&);

    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:
    myAudioProcessor& processor;
    std::vector<String> allMessages;
    String bigMess;
    int backslashCounter = 0;
};
