#pragma once

#include "Background.h"
#include "ButtonLNF.h"

class WelcomePage : public Component
{
public:
    explicit WelcomePage(std::function<void()> startButtonCallback);
    void resized() override;

private:
    void setHeader();

    ButtonLNF lnf;
    Background background;
    juce::Label header {"Header", "Welcome To Liron's Tic Tac Toe"};
    juce::TextButton startButton {"START"};

};