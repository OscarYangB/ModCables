/*
  ==============================================================================

    BlockComponent.h
    Created: 9 May 2025 12:23:49pm
    Author:  Oscar

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class BlockComponent : public juce::Component
{
public:
    BlockComponent();
    
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;
    void refreshMouseDragAnchor();
    void setBlockBounds(int x, int y, int w, int h);
    void setLocation(juce::Point<int> newLocation);

    juce::Point<int> dragStart = juce::Point<int>();
    juce::Point<int> anchorPoint = juce::Point<int>();
    juce::Point<int> currentPoint = juce::Point<int>();
};
