#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"

class Block : public juce::Component
{
public:
	Block();
	~Block();

	void paint(juce::Graphics&) override;

private:
	juce::Image backgroundImage = juce::ImageFileFormat::loadFrom(
		BinaryData::Background_png, BinaryData::Background_pngSize);
	juce::Slider knob;
};

