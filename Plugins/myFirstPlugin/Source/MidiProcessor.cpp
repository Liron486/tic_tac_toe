#include "MidiProcessor.h"

void MidiProcessor::process(MidiBuffer& midiMessages)
{
    for (auto message: midiMessages)
        messages.addMessage(message.getMessage().getDescription());
}


