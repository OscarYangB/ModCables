#include "Oscillator.h"

Oscillator::Oscillator(OscillatorParams* newParams)
{
	params = newParams;

	name.setText("1", juce::sendNotification);
	name.setInterceptsMouseClicks(false, false);
	name.setColour(name.textColourId, juce::Colour::fromRGB(0, 0, 0));
	addAndMakeVisible(name);

	sin.button.setToggleState(true, true);
	sin.button.addListener(this);
	addAndMakeVisible(sin);
	square.button.addListener(this);
	addAndMakeVisible(square);
	triangle.button.addListener(this);
	addAndMakeVisible(triangle);
	saw.button.addListener(this);
	addAndMakeVisible(saw);

	volumeLabel.setText("Volume", juce::sendNotification);
	volumeLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(volumeLabel);
	pitchLabel.setText("Pitch", juce::sendNotification);
	pitchLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(pitchLabel);
	phaseLabel.setText("Phase", juce::sendNotification);
	phaseLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(phaseLabel);

	volume.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	volume.setRange(0.0, 500.0);
	volume.setValue(100.0f);
	volume.setDoubleClickReturnValue(true, 50.f);
	volume.setTextValueSuffix("%");
	volume.addListener(this);
	addAndMakeVisible(volume);

	pitch.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	pitch.setRange(-500.f, 500.f);
	pitch.setValue(0.0f);
	pitch.setDoubleClickReturnValue(true, 0.f);
	pitch.setTextValueSuffix("%");
	pitch.addListener(this);
	addAndMakeVisible(pitch);

	phase.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	phase.setRange(0.0f, 359.f);
	phase.setValue(0.0f);
	phase.setDoubleClickReturnValue(true, 0.f);
	phase.setTextValueSuffix(" deg");
	phase.addListener(this);
	addAndMakeVisible(phase);

	attackLabel.setText("Attack", juce::sendNotification);
	attackLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(attackLabel);
	decayLabel.setText("Decay", juce::sendNotification);
	decayLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(decayLabel);
	sustainLabel.setText("Sustain", juce::sendNotification);
	sustainLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(sustainLabel);
	releaseLabel.setText("Release", juce::sendNotification);
	releaseLabel.setInterceptsMouseClicks(false, false);
	addAndMakeVisible(releaseLabel);
	
	attack.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	attack.setRange(0.0f, 2000.0f);
	attack.setValue(10.0f);
	attack.setDoubleClickReturnValue(true, 10.f);
	attack.setSkewFactor(0.5f);
	attack.setTextValueSuffix(" ms");
	attack.addListener(this);
	addAndMakeVisible(attack);

	decay.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	decay.setRange(0.0f, 2000.f);
	decay.setValue(50.0f);
	decay.setDoubleClickReturnValue(true, 50.f);
	decay.setSkewFactor(0.5f);
	decay.setTextValueSuffix(" ms");
	decay.addListener(this);
	addAndMakeVisible(decay);

	sustain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	sustain.setRange(0.0f, 100.f);
	sustain.setValue(100.0f);
	sustain.setDoubleClickReturnValue(true, 100.f);
	sustain.setTextValueSuffix("%");
	sustain.addListener(this);
	addAndMakeVisible(sustain);

	release.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	release.setRange(0.0f, 2000.f);
	release.setValue(100.0f);
	release.setDoubleClickReturnValue(true, 100.f);
	release.setSkewFactor(0.5f);
	release.setTextValueSuffix(" ms");
	release.addListener(this);
	addAndMakeVisible(release);

	addAndMakeVisible(keyTrack);

	addAndMakeVisible(volumeMod);
	addAndMakeVisible(pitchMod);
	addAndMakeVisible(phaseMod);
	addAndMakeVisible(output);

	setSize(100, 100);
}

Oscillator::~Oscillator()
{

}

void Oscillator::paint(juce::Graphics& g)
{
	g.drawImage(backgroundImage, 0.0f, 0.0f, getWidth(), getHeight(), 0.0f, 0.0f, backgroundImage.getWidth(), backgroundImage.getHeight());

	name.setBounds(14, -9, 50, 50);

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

void Oscillator::buttonClicked(juce::Button*)
{
}

void Oscillator::updateOscillatorParams()
{
	params->volume = volume.getValue() / 100.f;
	params->pitch = pitch.getValue();
	params->phase = pitch.getValue();

	params->keyTrack = keyTrack.button.getToggleState();

	params->attack = attack.getValue() / 1000.f;
	params->decay = decay.getValue() / 1000.f;
	params->sustain = sustain.getValue() / 100.f;
	params->release = release.getValue() / 1000.f;

	if (sin.button.getToggleState()) {
		params->type = OscillatorType::SIN;
	}
	else if (square.button.getToggleState()) {
		params->type = OscillatorType::SQUARE;
	}
	else if (triangle.button.getToggleState()) {
		params->type = OscillatorType::TRIANGLE;
	}
	else if (saw.button.getToggleState()) {
		params->type = OscillatorType::SAW;
	}
}

void Oscillator::addConnectedOscillator(Connector* connector, Oscillator* oscillator)
{
	switch (connector->getType()) {
	case AM:
		params->amplitudeModSources.push_back(oscillator);
		break;
	case FM:
		params->pitchModSources.push_back(oscillator);
		break;
	case PM:
		params->phaseModSources.push_back(oscillator);
		break;
	default:
		break;
	}
}

OscillatorParams* Oscillator::getOscillatorParams()
{
	return params;
}

void Oscillator::buttonStateChanged(juce::Button* button)
{
	if (button == &keyTrack.button) {
		updateOscillatorParams();
		return;
	}

	if (!button->getToggleState()) {
		return;
	}

	sin.button.setToggleState(false, false);
	sin.button.setInterceptsMouseClicks(true, false);
	

	square.button.setToggleState(false, false);
	square.button.setInterceptsMouseClicks(true, false);


	triangle.button.setToggleState(false, false);
	triangle.button.setInterceptsMouseClicks(true, false);


	saw.button.setToggleState(false, false);
	saw.button.setInterceptsMouseClicks(true, false);


	button->setToggleState(true, false);
	button->setInterceptsMouseClicks(false, false);

	updateOscillatorParams();
}

void Oscillator::sliderValueChanged(juce::Slider* slider)
{
	updateOscillatorParams();
}
