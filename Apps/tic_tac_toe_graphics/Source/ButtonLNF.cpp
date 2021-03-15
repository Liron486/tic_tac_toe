#include <JuceHeader.h>

#include "ButtonLNF.h"


Font ButtonLNF::getTextButtonFont(TextButton& button, int buttonHeight)
{
    return Font (jmin (fontSize, (float) buttonHeight * 0.6f));
}
