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

	volumeLabel.setText("Volume", juce::sendNotification);
	addAndMakeVisible(volumeLabel);
	pitchLabel.setText("Pitch", juce::sendNotification);
	addAndMakeVisible(pitchLabel);
	phaseLabel.setText("Phase", juce::sendNotification);
	addAndMakeVisible(phaseLabel);

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

	attackLabel.setText("Attack", juce::sendNotification);
	addAndMakeVisible(attackLabel);
	decayLabel.setText("Decay", juce::sendNotification);
	addAndMakeVisible(decayLabel);
	sustainLabel.setText("Sustain", juce::sendNotification);
	addAndMakeVisible(sustainLabel);
	releaseLabel.setText("Release", juce::sendNotification);
	addAndMakeVisible(releaseLabel);
	
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

	volumeMod.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Yellow_png, BinaryData::EmptyConnector_Yellow_pngSize)));
	addAndMakeVisible(volumeMod);
	
	juce::Image image = juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_png, BinaryData::EmptyConnector_pngSize));
	pitchMod.setImage(image);
	addAndMakeVisible(pitchMod);

	phaseMod.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Red_png, BinaryData::EmptyConnector_Red_pngSize)));
	addAndMakeVisible(phaseMod);

	output.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Gray_png, BinaryData::EmptyConnector_Gray_pngSize)));
	addAndMakeVisible(output);

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
	float bottomYPosition = getHeight() - knobWidth - 5.f;

	volumeLabel.setBounds(115, 40, 100, 10);
	pitchLabel.setBounds(100, 80, 100, 10);
	phaseLabel.setBounds(125, 120, 100, 10);

	attackLabel.setBounds(0, bottomYPosition, 100, 10);
	decayLabel.setBounds(50, bottomYPosition, 100, 10);
	sustainLabel.setBounds(100, bottomYPosition, 100, 10);
	releaseLabel.setBounds(150, bottomYPosition, 100, 10);
	
	volume.setBounds(getWidth() - knobWidth, 20, knobWidth, knobWidth);
	pitch.setBounds(getWidth() - knobWidth, 60, knobWidth, knobWidth);
	keyTrack.setBounds(pitch.getX() - 30.f, pitch.getY() + 5, 40.f, 40.f);
	phase.setBounds(getWidth() - knobWidth, 100, knobWidth, knobWidth);

	attack.setBounds(0.f, bottomYPosition, knobWidth, knobWidth);
	decay.setBounds(50.f, bottomYPosition, knobWidth, knobWidth);
	sustain.setBounds(100.f, bottomYPosition, knobWidth, knobWidth);
	release.setBounds(150.f, bottomYPosition, knobWidth, knobWidth);

	volumeMod.setBounds(5, 45, 25, 25);
	pitchMod.setBounds(5, 80, 25, 25);
	phaseMod.setBounds(5, 115, 25, 25);
	output.setBounds(getWidth() - 35, 5, 25, 25);
}
