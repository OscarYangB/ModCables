#include "Block.h"

Block::Block()
{
	name.setText("1", juce::sendNotification);
	name.setColour(name.textColourId, juce::Colour::fromRGB(0, 0, 0));
	addAndMakeVisible(name);

	addAndMakeVisible(sin);
	addAndMakeVisible(square);
	addAndMakeVisible(triangle);
	addAndMakeVisible(saw);

	volume.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	volume.setRange(0.0, 100.0);
	volume.setValue(50.0f);
	volume.setDoubleClickReturnValue(true, 50.f);
	volume.setTextValueSuffix("%");
	addAndMakeVisible(volume);

	pitch.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	pitch.setRange(-200.f, 200.f);
	pitch.setValue(0.0f);
	pitch.setDoubleClickReturnValue(true, 0.f);
	pitch.setTextValueSuffix("%");
	addAndMakeVisible(pitch);

	phase.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	phase.setRange(0.0f, 359.f);
	phase.setValue(0.0f);
	phase.setDoubleClickReturnValue(true, 0.f);
	phase.setTextValueSuffix(" deg");
	addAndMakeVisible(phase);
	
	attack.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	attack.setRange(0.0f, 2000.0f);
	attack.setValue(10.0f);
	attack.setDoubleClickReturnValue(true, 10.f);
	attack.setSkewFactor(0.5f);
	attack.setTextValueSuffix(" ms");
	addAndMakeVisible(attack);

	decay.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	decay.setRange(0.0f, 2000.f);
	decay.setValue(50.0f);
	decay.setDoubleClickReturnValue(true, 50.f);
	decay.setSkewFactor(0.5f);
	decay.setTextValueSuffix(" ms");
	addAndMakeVisible(decay);

	sustain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	sustain.setRange(0.0f, 100.f);
	sustain.setValue(100.0f);
	sustain.setDoubleClickReturnValue(true, 100.f);
	sustain.setTextValueSuffix("%");
	addAndMakeVisible(sustain);

	release.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	release.setRange(0.0f, 2000.f);
	release.setValue(100.0f);
	release.setDoubleClickReturnValue(true, 100.f);
	release.setSkewFactor(0.5f);
	release.setTextValueSuffix(" ms");
	addAndMakeVisible(release);

	addAndMakeVisible(keyTrack);

	setSize(100, 100);
}

Block::~Block()
{

}

void Block::paint(juce::Graphics& g)
{
	g.drawImage(backgroundImage, 0.0f, 0.0f, getWidth(), getHeight(), 0.0f, 0.0f, backgroundImage.getWidth(), backgroundImage.getHeight());

	name.setBounds(10, -7, 50, 50);

	sin.setBounds(40, 0, 40.f, 40.f);
	square.setBounds(40 + 29, 0, 40.f, 40.f);
	triangle.setBounds(40 + 29 * 2, 0, 40.f, 40.f);
	saw.setBounds(40 + 29 * 3, 0, 40.f, 40.f);

	float knobWidth = 45.f;

	volume.setBounds(getWidth() - knobWidth, 20, knobWidth, knobWidth);
	pitch.setBounds(getWidth() - knobWidth, 60, knobWidth, knobWidth);
	keyTrack.setBounds(pitch.getX() - 30.f, pitch.getY(), 40.f, 40.f);
	phase.setBounds(getWidth() - knobWidth, 100, knobWidth, knobWidth);

	attack.setBounds(0.f, getHeight() - knobWidth - 5.f, knobWidth, knobWidth);
	decay.setBounds(50.f, getHeight() - knobWidth - 5.f, knobWidth, knobWidth);
	sustain.setBounds(100.f, getHeight() - knobWidth - 5.f, knobWidth, knobWidth);
	release.setBounds(150.f, getHeight() - knobWidth - 5.f, knobWidth, knobWidth);

}
