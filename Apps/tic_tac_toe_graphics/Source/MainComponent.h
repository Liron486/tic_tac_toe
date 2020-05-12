#pragma once

#include <JuceHeader.h>

class MainComponent   : public Component
{
public:

    MainComponent();

    void paint (Graphics&) override;
    void resized() override;


    void mouseDown(const MouseEvent& event) override;
private:
    std::vector<Rectangle<float>> rects;

};
