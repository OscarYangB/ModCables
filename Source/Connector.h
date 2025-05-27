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
    AM,
    FM,
    PM,
    OUT
};

class Oscillator;

class Connector : public juce::Component, juce::Timer
{
public:
    Connector(ConnectorColour newColour, Oscillator* newOscillator);
    Connector();

    void mouseDown(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    void paint(juce::Graphics& g) override;

    void timerCallback();

    Oscillator* getOscillator();
    ConnectorColour getType();
 
private:
    ConnectorColour colour;
    juce::ImageComponent image = juce::ImageComponent();
    Oscillator* oscillator;

    std::vector<BlockLink*> connections = std::vector<BlockLink*>();
    BlockLink* draggingConnection = nullptr;
};
