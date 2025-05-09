#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"
#include "IconButton.h"
#include "BlockComponent.h"

class Oscillator : public BlockComponent
{
public:
	Oscillator();
	~Oscillator();

	void paint(juce::Graphics&) override;

private:
	juce::Image backgroundImage = juce::ImageFileFormat::loadFrom(BinaryData::Background_png, BinaryData::Background_pngSize);
	juce::Label name;

	IconButton sin = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	IconButton square = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Square_png, BinaryData::Square_pngSize));
	IconButton triangle = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Triangle_png, BinaryData::Triangle_pngSize));
	IconButton saw = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Saw_png, BinaryData::Saw_pngSize));

	juce::Label volumeLabel;
	juce::Label pitchLabel;
	juce::Label phaseLabel;

	juce::Slider volume;
	juce::Slider pitch;
	IconButton keyTrack = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	juce::Slider phase;

	juce::Label attackLabel;
	juce::Label decayLabel;
	juce::Label sustainLabel;
	juce::Label releaseLabel;

	juce::Slider attack;
	juce::Slider decay;
	juce::Slider sustain;
	juce::Slider release;

	juce::ImageComponent volumeMod;
	juce::ImageComponent pitchMod;
	juce::ImageComponent phaseMod;
	juce::ImageComponent output;
};

