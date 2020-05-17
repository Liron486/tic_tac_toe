#include "PluginProcessor.h"
#include "PluginEditor.h"

NewPluginTemplateAudioProcessor::NewPluginTemplateAudioProcessor()
    : AudioProcessor(getBuses())
{
    volume = new AudioParameterFloat("Volume", "Volume", 0.f, 1.f, 1.f);
    addParameter(volume);
}

void NewPluginTemplateAudioProcessor::prepareToPlay(double /*sampleRate*/,
                                                    int /*blockSize*/)
{
}

void NewPluginTemplateAudioProcessor::processBlock(AudioBuffer<float>& buffer,
                                                   MidiBuffer& midiMessages)
{
    midiMessages.clear();

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto channelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] *= volume->get();
        }
    }
}

AudioProcessorEditor* NewPluginTemplateAudioProcessor::createEditor()
{
    return new GenericAudioProcessorEditor(*this);
}

AudioProcessor::BusesProperties NewPluginTemplateAudioProcessor::getBuses()
{
    auto stereo = AudioChannelSet::stereo();

    return BusesProperties()
        .withInput("Input", stereo, true)
        .withOutput("Output", stereo, true);
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewPluginTemplateAudioProcessor();
}
