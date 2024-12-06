/*
  ==============================================================================

    BlockLookAndFeel.h
    Created: 6 Dec 2024 2:38:37pm
    Author:  Oscar

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class BlockLookAndFeel : public juce::LookAndFeel_V4 
{
public:
    void drawRotarySlider(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPosProportional,
        float rotaryStartAngle, float rotaryEndAngle,
        juce::Slider& slider) override;

    juce::Font getLabelFont(juce::Label& label) override;

    juce::Label* createSliderTextBox(juce::Slider& slider) override;

private:
    juce::Image knobBackground = juce::ImageFileFormat::loadFrom(
        BinaryData::KnobBackground_png, BinaryData::KnobBackground_pngSize);
    juce::Image knobSlider = juce::ImageFileFormat::loadFrom(
        BinaryData::KnobForeground_png, BinaryData::KnobForeground_pngSize);
};
