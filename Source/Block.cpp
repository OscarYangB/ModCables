#include "Block.h"

Block::Block() 
{
	knob.setSliderStyle(juce::Slider::RotaryVerticalDrag);
	knob.setRange(0.0, 100.0);
	knob.setValue(50.0);
	addAndMakeVisible(knob);

	setSize(50, 50);
}

Block::~Block()
{

}

void Block::paint(juce::Graphics& g)
{
	g.drawImage(backgroundImage, 0.0f, 0.0f, 50.0f, 50.0f, 0.0f, 0.0f, 880.0f, 880.0f);
	g.drawRect(10, 10, 75, 75);
	knob.setBounds(10,10,75,75);
	
}
