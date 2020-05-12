#pragma once

#include <JuceHeader.h>

class MainComponent   : public Component
{
public:

    MainComponent();

    void paint (Graphics&) override;
    void resized() override;

    void mouseDown(const MouseEvent& event) override;
    void mouseDrag(const MouseEvent& event) override;

private:
    Rectangle<float>* getRectUnder(Point<float> position);

    Rectangle<float>* draggedRect = nullptr;

    std::vector<Rectangle<float>> rects;

};
