/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "BlockComponent.h"
#include "Oscillator.h"

//==============================================================================
/**
*/
class ModCablesAudioProcessorEditor  : public juce::AudioProcessorEditor, juce::Timer
{
public:
    ModCablesAudioProcessorEditor (ModCablesAudioProcessor&);
    ~ModCablesAudioProcessorEditor() override;

    void timerCallback();

    void updateDragging();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    void refreshMouseDragAnchor();
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ModCablesAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModCablesAudioProcessorEditor)

    juce::Point<int> dragStart;
    juce::Point<int> anchorPoint;
    juce::Point<int> currentPoint;
    juce::Point<int> location;

    juce::ComboBox options;
    std::vector<BlockComponent*> blockComponents = std::vector<BlockComponent*>();
    BlockLookAndFeel globalLookAndFeel;

    void optionSelected();
    void addOscillator();
};
