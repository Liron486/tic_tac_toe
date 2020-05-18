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
            newMessage = messages.back();
            messages.pop_back();
        }
        return newMessage;
    }

    void addMessage(String newMessage) {messages.push_back(newMessage);}

private:
    std::vector<String> messages;

};


class MidiProcessor
{
public:
    void process(MidiBuffer& midiMessages);
    String getLastMessage() { return messages.getNextMessage(); }

private:
    void processMidiInput(const MidiBuffer& midiMessages);
    void addTransposedNote(MidiMessage messageToTranspose, int samplePos);

    MidiMessage currentMessage;
    messagesVector messages;
    MidiBuffer processBuffer;
};
