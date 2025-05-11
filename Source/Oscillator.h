#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"
#include "IconButton.h"
#include "BlockComponent.h"
#include "PluginProcessor.h"

class Oscillator : public BlockComponent, juce::Button::Listener, juce::Slider::Listener
{
public:
	Oscillator(OscillatorParams* newParams);
	~Oscillator();

	void paint(juce::Graphics&) override;

	juce::Label name;

	void buttonClicked(juce::Button*) override;
	void buttonStateChanged(juce::Button* button) override;
	void sliderValueChanged(juce::Slider* slider) override;

	juce::Slider attack;
	juce::Slider decay;
	juce::Slider sustain;
	juce::Slider release;

	IconButton sin = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	IconButton square = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Square_png, BinaryData::Square_pngSize));
	IconButton triangle = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Triangle_png, BinaryData::Triangle_pngSize));
	IconButton saw = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Saw_png, BinaryData::Saw_pngSize));

	juce::Slider volume;
	juce::Slider pitch;
	IconButton keyTrack = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	juce::Slider phase;

	void Oscillator::updateOscillatorParams();


private:
	juce::Image backgroundImage = juce::ImageFileFormat::loadFrom(BinaryData::Background_png, BinaryData::Background_pngSize);
	
	juce::Label volumeLabel;
	juce::Label pitchLabel;
	juce::Label phaseLabel;

	juce::Label attackLabel;
	juce::Label decayLabel;
	juce::Label sustainLabel;
	juce::Label releaseLabel;

	juce::ImageComponent volumeMod;
	juce::ImageComponent pitchMod;
	juce::ImageComponent phaseMod;
	juce::ImageComponent output;

	OscillatorParams* params;
};

