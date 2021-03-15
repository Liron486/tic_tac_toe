#pragma once

class ButtonLNF : public LookAndFeel_V4
{
public:
    Font getTextButtonFont(TextButton& button, int buttonHeight) override;

    void setFontSize(float newFontSize) { fontSize = newFontSize; }

private:
    float fontSize {23.f};
};