#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"
#include "IconButton.h"

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
	IconButton button = IconButton(juce::ImageFileFormat::loadFrom(
		BinaryData::Sin_png, BinaryData::Sin_pngSize));
};

