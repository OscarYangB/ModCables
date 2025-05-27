/*
  ==============================================================================

    BlockLink.h
    Created: 15 May 2025 2:43:13pm
    Author:  Oscar

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>

class BlockLink : public juce::Component, juce::Timer {
public:
    BlockLink(juce::Point<int> newStart);

    void paint(juce::Graphics& g) override;
    void timerCallback();
    
    bool isDragging = true;

private:
    juce::Point<int> start;
    juce::Point<int> endPoint;
};