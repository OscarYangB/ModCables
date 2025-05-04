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
	juce::Image backgroundImage = juce::ImageFileFormat::loadFrom(BinaryData::Background_png, BinaryData::Background_pngSize);
	juce::Label name;

	IconButton sin = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	IconButton square = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Square_png, BinaryData::Square_pngSize));
	IconButton triangle = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Triangle_png, BinaryData::Triangle_pngSize));
	IconButton saw = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Saw_png, BinaryData::Saw_pngSize));

	juce::Slider volume;
	juce::Slider pitch;
	IconButton keyTrack = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	juce::Slider phase;

	juce::Slider attack;
	juce::Slider decay;
	juce::Slider sustain;
	juce::Slider release;
};

