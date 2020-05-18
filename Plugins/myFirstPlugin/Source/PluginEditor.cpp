#include "PluginProcessor.h"
#include "PluginEditor.h"

myAudioProcessorEditor::myAudioProcessorEditor (myAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    allMessages.emplace_back("");
    startTimerHz(1000);
    setSize (400, 300);
}

void myAudioProcessorEditor::paint (Graphics& g)
{

    String text = processor.getMidiProcessor().getLastMessage();

    if (text.isNotEmpty())
    {
        bigMess += text + "\n";
        ++backslashCounter;

        if (backslashCounter > 18)
        {
            String newString;
            newString = bigMess.fromFirstOccurrenceOf("\n", false, true);
            bigMess = newString;
        }
    }

    Justification justify(4);

    g.setColour(Colours::white);
    g.drawMultiLineText(bigMess, 10, 25, getLocalBounds().getWidth() - 20);

}

void myAudioProcessorEditor::resized()
{
}

void myAudioProcessorEditor::timerCallback()
{
    repaint();
}
