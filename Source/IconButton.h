/*
  ==============================================================================

    IconButton.h
    Created: 15 Dec 2024 2:26:08pm
    Author:  Oscar

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"

class IconButton : public juce::Component
{
public:
	IconButton(juce::Image newIcon);
	~IconButton();

	void paint(juce::Graphics&) override;

private:
	juce::ToggleButton button;
	juce::ImageComponent icon;
	juce::Label label;
};


