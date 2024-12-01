/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModCablesAudioProcessorEditor::ModCablesAudioProcessorEditor (ModCablesAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    startTimer(20);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ModCablesAudioProcessorEditor::~ModCablesAudioProcessorEditor()
{
}

void ModCablesAudioProcessorEditor::timerCallback() 
{
    juce::Point<int> mousePosition = getMouseXYRelative();

    if (juce::ModifierKeys::currentModifiers.isLeftButtonDown() != isDragging) {
        dragStart = mousePosition;
        anchorPoint = currentPoint;
        isDragging = !isDragging;
    }

    if (!isDragging) {
        return;
    }
    
    currentPoint = anchorPoint + mousePosition - dragStart;
    repaint();
}


//==============================================================================
void ModCablesAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    g.drawRect(juce::Rectangle<float>(100, 100, 200, 200));
    g.drawImage(backgroundImage, currentPoint.getX(), currentPoint.getY(), 50.0f, 50.0f, 0.0f, 0.0f, 880.0f, 880.0f);
}

void ModCablesAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
