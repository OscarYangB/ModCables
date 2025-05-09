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
    juce::LookAndFeel::setDefaultLookAndFeel(&globalLookAndFeel);
    addAndMakeVisible(block);

    addAndMakeVisible(options);
    options.addItem("Create Oscillator", 1);
    options.addItem("Create Output", 2);
    options.setVisible(false);
    options.onChange = [this] { optionSelected(); };

    startTimer(16);
    setSize(700, 700);
}

ModCablesAudioProcessorEditor::~ModCablesAudioProcessorEditor()
{
}

void ModCablesAudioProcessorEditor::timerCallback() 
{
    updateDragging();
}

void ModCablesAudioProcessorEditor::updateDragging() 
{
    location += (currentPoint - location) / 2.f;
    repaint();
}

//==============================================================================
void ModCablesAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colour::fromRGB(73, 62, 53));

    /*
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    g.drawRect(juce::Rectangle<float>(100, 100, 200, 200));
    g.drawImage(backgroundImage, currentPoint.getX(), currentPoint.getY(), 50.0f, 50.0f, 0.0f, 0.0f, 880.0f, 880.0f);
    */

    block.setBlockBounds(location.x, location.y, 200, 200);
}

void ModCablesAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void ModCablesAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown()) 
    {
        refreshMouseDragAnchor();
    }
    else if (event.mods.isRightButtonDown()) {
        options.setBounds(event.getMouseDownPosition().x, event.getMouseDownPosition().y, 50, 0);
        options.showPopup();
    }
}

void ModCablesAudioProcessorEditor::mouseUp(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        refreshMouseDragAnchor();
    }
}

void ModCablesAudioProcessorEditor::mouseDrag(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown()) {
        currentPoint = anchorPoint + getMouseXYRelative() - dragStart;
    }
}

void ModCablesAudioProcessorEditor::refreshMouseDragAnchor()
{
    dragStart = getMouseXYRelative();
    anchorPoint = currentPoint;
}

void ModCablesAudioProcessorEditor::optionSelected()
{
    switch (options.getSelectedId())
    {
    case 1:
        // Create oscillator
        break;
    case 2:
        // Create Listener
        break;
    default:
        break;
    }

    options.setSelectedId(-1);
}
