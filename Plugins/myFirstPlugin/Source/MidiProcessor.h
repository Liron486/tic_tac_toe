#pragma once

#include <vector>

#include "JuceHeader.h"


class messagesVector
{
public:
    String getNextMessage()
    {
        String newMessage;
        if (!messages.empty())
        {
            ScopedLock lock(criticalSection);
            newMessage = messages.back();
            messages.pop_back();
        }
        return newMessage;
    }

    void addMessage(String newMessage) {messages.push_back(newMessage);}
    CriticalSection& getCriticalSection() { return criticalSection; }

private:
    std::vector<String> messages;
    CriticalSection criticalSection;

};


class MidiProcessor
{
public:
    void process(MidiBuffer& midiMessages);
    String getLastMessage() { return messages.getNextMessage(); }
    CriticalSection& getCriticalSection() { return messages.getCriticalSection(); }

private:
    void processMidiInput(const MidiBuffer& midiMessages);
    void addTransposedNote(MidiMessage messageToTranspose, int samplePos);

    MidiMessage currentMessage;
    messagesVector messages;
    MidiBuffer processBuffer;
};
