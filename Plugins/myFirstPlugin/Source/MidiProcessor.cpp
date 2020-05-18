#include "MidiProcessor.h"

constexpr int interval = 35;

void MidiProcessor::process(MidiBuffer& midiMessages)
{
    processBuffer.clear();
    processMidiInput(midiMessages);
    midiMessages.swapWith(processBuffer);
}
void MidiProcessor::processMidiInput(const MidiBuffer& midiMessages)
{
    MidiBuffer::Iterator it(midiMessages);
    int samplePos;

    while (it.getNextEvent(currentMessage, samplePos))
    {
        if (currentMessage.isNoteOnOrOff())
            addTransposedNote(currentMessage, samplePos);

        processBuffer.addEvent(currentMessage, samplePos);
        messages.addMessage(currentMessage.getDescription());
    }
}
void MidiProcessor::addTransposedNote(MidiMessage messageToTranspose,
                                      int samplePos)
{
    auto oldNoteNum = messageToTranspose.getNoteNumber();
    messageToTranspose.setNoteNumber(oldNoteNum + interval);

    messages.addMessage(messageToTranspose.getDescription());

    processBuffer.addEvent(messageToTranspose, samplePos);
}

