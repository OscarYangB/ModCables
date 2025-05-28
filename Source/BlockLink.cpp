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
    setInterceptsMouseClicks(false, false);
    start = newStart;
    startTimer(16);
}

void BlockLink::paint(juce::Graphics& g)
{
    if (isDragging) {
        endPoint = juce::Point<int>(getMouseXYRelative().x, getMouseXYRelative().y);
    }
    
    g.drawLine(start.x, start.y, endPoint.x, endPoint.y, 3.f);
}

void BlockLink::timerCallback()
{
    //repaint();
}
