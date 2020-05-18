#pragma once

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
};
