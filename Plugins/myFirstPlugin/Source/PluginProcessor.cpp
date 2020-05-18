#include "PluginProcessor.h"
#include "PluginEditor.h"

myAudioProcessor::myAudioProcessor()
    : AudioProcessor(getBuses())
{

}

void myAudioProcessor::prepareToPlay(double /*sampleRate*/,
                                                    int /*blockSize*/)
{
}

void myAudioProcessor::processBlock(AudioBuffer<float>& buffer,
                                                   MidiBuffer& midiMessages)
{
    buffer.clear();
    midiProcessor.process(midiMessages);
}

AudioProcessorEditor* myAudioProcessor::createEditor()
{
    return new myAudioProcessorEditor(*this);
}

AudioProcessor::BusesProperties myAudioProcessor::getBuses()
{
    auto stereo = AudioChannelSet::stereo();

    return BusesProperties()
        .withInput("Input", stereo, true)
        .withOutput("Output", stereo, true);
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new myAudioProcessor();
}
