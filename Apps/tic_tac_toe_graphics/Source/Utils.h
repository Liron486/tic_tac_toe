#pragma once

#include <JuceHeader.h>

#include "ButtonLNF.h"

template <typename T>
static void resizedCells(std::vector<std::unique_ptr<T>>& vector)
{
    const auto numOfRows = 3;
    const auto numOfCols = 3;

    auto x = 0.f;
    auto y = 0.f;
    auto width = 1.f / (float) numOfCols;
    auto hight = 1.f / (float) numOfRows;
    auto cellIdx = 0;

    for (auto i = 1; i <= numOfCols; ++i)
    {
        for (auto j = 1; j <= numOfRows; ++j)
        {
            if (vector[cellIdx])
                vector[cellIdx]->setBoundsRelative(x, y, width, hight);

            x += width;
            ++cellIdx;
        }

        x = 0.f;
        y += hight;
    }
}

static void drawGrid(Graphics& g, float width, float height, float alpha)
{
    g.setColour(Colours::black.withAlpha(alpha));

    g.drawLine(0, height / 3.f, width, height / 3.f, 8);
    g.drawLine(0, (height * 2) / 3.f, width, (height * 2) / 3.f, 8);
    g.drawLine(width / 3.f, 0, width / 3.f, height, 8);
    g.drawLine((width * 2) / 3.f, 0, (width * 2) / 3.f, height, 8);
}

static int anyButtonPressed(std::vector<std::unique_ptr<juce::TextButton>>& vector,
                            const std::function<bool(int)>& conditionFunc,
                            const std::function<void(int)>& assignmentFunc)
{
    auto onIndex = 0;

    for (auto i = 0; i < vector.size(); ++i)
    {
        if (vector[i]->getToggleState() && conditionFunc(i))
        {
            assignmentFunc(i);
            break;
        }
    }

    for (auto i = 0; i < vector.size(); ++i)
    {
        if (conditionFunc(i))
            vector[i]->setToggleState(false, juce::dontSendNotification);

        else
        {
            vector[i]->setToggleState(true, juce::dontSendNotification);
            onIndex = i;
        }
    }

    return onIndex;
}

static void setLabels(
    Label& label,
    Colour color = Colours::black,
    Justification justtification = Justification::centredLeft,
    float fontHeight = 20.f)
{
    label.setColour(label.textColourId, color);
    label.setJustificationType(justtification);

    auto font = label.getFont();

    font.setHeight(fontHeight);
    font.setTypefaceName("Century Ghotic");
    label.setFont(font);
}

static void setButton(juce::TextButton& button, ButtonLNF& lnf)
{
    button.setColour(button.textColourOffId, juce::Colours::black);
    button.setColour(button.buttonColourId, juce::Colours::seashell);
    button.setColour(button.buttonOnColourId, juce::Colours::navy);
    button.setLookAndFeel(&lnf);
    button.setClickingTogglesState(true);
}

static void
    setButtonConnectedFlags(juce::TextButton& button, int buttonIndex, int endIndex)
{
    auto connectedFalgs = 0;

    if (buttonIndex != 0)
        connectedFalgs = Button::ConnectedOnLeft;

    if (buttonIndex != endIndex)
        connectedFalgs |= Button::ConnectedOnRight;

    button.setConnectedEdges(connectedFalgs);
}

static void setTextToBold(juce::Label& label, bool isBold)
{
    auto font = label.getFont();
    font.setBold(isBold);
    label.setFont(font);
}
