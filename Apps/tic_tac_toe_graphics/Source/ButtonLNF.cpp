#include <JuceHeader.h>

#include "ButtonLNF.h"


Font ButtonLNF::getTextButtonFont(TextButton& button, int buttonHeight)
{
    auto buttonFont = Font(jmin (fontSize, (float) buttonHeight * 0.6f));
    buttonFont.setTypefaceName("Century Gothic");
    buttonFont.setBold(true);

    return buttonFont;
}
