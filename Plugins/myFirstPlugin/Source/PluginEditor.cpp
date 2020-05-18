#include "PluginProcessor.h"
#include "PluginEditor.h"

myAudioProcessorEditor::myAudioProcessorEditor (myAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    startTimerHz(1);
    setSize (400, 300);
}

void myAudioProcessorEditor::paint (Graphics& g)
{
    String text = processor.getMidiProcessor().getLastMessage();
    Rectangle<int> rect(getLocalBounds().getTopLeft(), getLocalBounds().getBottomRight());
    Justification justify(4);

    g.drawText(text, rect, justify);
}

void myAudioProcessorEditor::resized()
{

}
void myAudioProcessorEditor::timerCallback()
{
    repaint();
}
