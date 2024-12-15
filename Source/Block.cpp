#include "Block.h"

Block::Block() 
{
	knob.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	knob.setRange(0.0, 100.0);
	knob.setValue(50.0);
	addAndMakeVisible(knob);

	addAndMakeVisible(button);

	setSize(100, 100);
}

Block::~Block()
{

}

void Block::paint(juce::Graphics& g)
{
	g.drawImage(backgroundImage, 0.0f, 0.0f, getWidth(), getHeight(), 0.0f, 0.0f,
		backgroundImage.getWidth(), backgroundImage.getHeight());
	knob.setBounds(10,10,75,75);
	button.setBounds(0, 0, 40, 40);	
}
