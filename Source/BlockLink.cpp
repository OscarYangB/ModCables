/*
  ==============================================================================

    BlockLink.cpp
    Created: 15 May 2025 2:43:13pm
    Author:  Oscar

  ==============================================================================
*/

#include "BlockLink.h"

BlockLink::BlockLink(juce::Component* newStartComp)
{
    setInterceptsMouseClicks(false, false);
    startComp = newStartComp;
    startTimer(16);
}

void BlockLink::paint(juce::Graphics& g)
{
    juce::Point<int> endPoint = juce::Point<int>();

    if (endComp == nullptr) {
        endPoint = juce::Point<int>(getMouseXYRelative().x, getMouseXYRelative().y);
    }
    else {
        endPoint = endComp->getScreenPosition() - getScreenPosition();
        endPoint += juce::Point<int>(endComp->getWidth() / 2.f, endComp->getHeight() / 2.f);
    }
    
    juce::Point<int> startPoint = startComp->getScreenPosition() - getScreenPosition();
    startPoint += juce::Point<int>(startComp->getWidth() / 2.f, startComp->getHeight() / 2.f);

    g.drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y, 8.f);
}

void BlockLink::timerCallback()
{
    //repaint();
}

void BlockLink::setEndComp(juce::Component* newEndComp)
{
    endComp = newEndComp;
}
