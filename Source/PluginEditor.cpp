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
    
    addAndMakeVisible(options);
    options.addItem("Create Oscillator", 1);
    options.addItem("Create Output", 2);
    options.setVisible(false);
    options.onChange = [this] { optionSelected(); };

    addAndMakeVisible(tuning);

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
    g.fillAll(juce::Colour::fromRGB(73, 62, 53));

    for (BlockComponent* blockComponent : blockComponents) 
    {
        blockComponent->setBlockBounds(location.x, location.y, 200, 200);
    }

    tuning.setBounds(0, 0, 200, 30);
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
        {
        addOscillator();
        break;
        }
    case 2:
        // Create Listener
        break;
    default:
        break;
    }

    options.setSelectedId(-1);
}

void ModCablesAudioProcessorEditor::addOscillator()
{
    OscillatorParams* params = new OscillatorParams();
    
    Oscillator* oscillator = new Oscillator(params);
    addAndMakeVisible(oscillator);
    blockComponents.push_back(oscillator);
    oscillator->setLocation(options.getPosition() - location);
    oscillator->name.setText((juce::String)blockComponents.size(), juce::sendNotification);

    oscillator->updateOscillatorParams();
    audioProcessor.oscillators.push_back(params);
}
