/*
  ==============================================================================

    BlockLink.cpp
    Created: 15 May 2025 2:43:13pm
    Author:  Oscar

  ==============================================================================
*/

#include "BlockLink.h"

BlockLink::BlockLink(juce::Point<int> newStart)
{
    start = newStart;
    startTimer(16);
}

void BlockLink::paint(juce::Graphics& g)
{
    g.drawLine(start.x, start.y, getMouseXYRelative().x, getMouseXYRelative().y, 3.f);
}

void BlockLink::timerCallback()
{
    //repaint();
}
