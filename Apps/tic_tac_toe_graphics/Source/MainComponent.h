#pragma once

#include <JuceHeader.h>



class Cell : public Component
{
public:

    void paint(Graphics&) override;

    void mouseDown(const MouseEvent& event) override;

private:
    int mouseDownCounter = 0;
};

class Board : public Component
{
public:
    Board();
	
	void paintOverChildren(Graphics& g) override;
    void resized() override;
    

private:
    std::vector<std::unique_ptr<Component>> cells;
};
