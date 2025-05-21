/*
  ==============================================================================

    Connector.h
    Created: 15 May 2025 10:10:13am
    Author:  Oscar

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "BlockLink.h"

enum ConnectorColour 
{
    RED,
    YELLOW,
    BLUE,
    GRAY
};

class Connector : public juce::Component, juce::Timer
{
public:
    Connector(ConnectorColour newColour);

    void mouseDown(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    void paint(juce::Graphics& g) override;

    void timerCallback();

private:
    ConnectorColour colour;
    juce::ImageComponent image;

    std::vector<BlockLink*> connections = std::vector<BlockLink*>();
    BlockLink* draggingConnection = nullptr;
};
