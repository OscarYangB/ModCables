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
    BlockLink(juce::Component* newStartComp);

    void paint(juce::Graphics& g) override;
    void timerCallback();
    
    void setEndComp(juce::Component* newEndComp);

private:
    juce::Component* startComp = nullptr;
    juce::Component* endComp = nullptr;
};