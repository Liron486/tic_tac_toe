#pragma once

#include <JuceHeader.h>
#include "MidiProcessor.h"

class myAudioProcessor : public AudioProcessor
{
public:
    myAudioProcessor();

    void prepareToPlay(double sampleRate, int blockSize) override;
    void releaseResources() override {};
    void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

    bool isBusesLayoutSupported(const BusesLayout&) const override { return true; }

    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const String getName() const override { return JucePlugin_Name; }

    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const String getProgramName(int) override { return String(); };
    void changeProgramName(int, const String& /*newName*/) override {}

    void getStateInformation(MemoryBlock& /*destData*/) override {}
    void setStateInformation(const void* /*data*/, int /*sizeInBytes*/) override {}

    static BusesProperties getBuses();
    MidiProcessor& getMidiProcessor() { return midiProcessor; }

private:
    MidiProcessor midiProcessor;
    AudioParameterFloat* volume;
};
