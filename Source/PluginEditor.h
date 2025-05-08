/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Block.h"

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
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ModCablesAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModCablesAudioProcessorEditor)

    juce::Point<int> dragStart;
    juce::Point<int> anchorPoint;
    juce::Point<int> currentPoint;
    bool isDragging = false;

    Block block;
    BlockLookAndFeel globalLookAndFeel;
};
