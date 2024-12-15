/*
  ==============================================================================

    BlockLookAndFeel.cpp
    Created: 6 Dec 2024 2:38:15pm
    Author:  Oscar

  ==============================================================================
*/

#include "BlockLookAndFeel.h"


void BlockLookAndFeel::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
    float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
    float scale = (float)juce::jmin(width, height) / knobBackground.getWidth();

    int backgroundWidth = knobBackground.getWidth() * scale;
    int backgroundHeight = knobBackground.getHeight() * scale;
    int backgroundX = x + width / 2.0f - backgroundWidth / 2.0f;
    int backgroundY = y + height / 2.0f - backgroundHeight / 2.0f;
    g.drawImage(knobBackground, backgroundX, backgroundY, backgroundWidth, backgroundHeight, 0.0f, 0.0f,
        knobBackground.getWidth(), knobBackground.getHeight());

    int sliderWidth = knobSlider.getWidth() * scale;
    int sliderHeight = knobSlider.getHeight() * scale;
    int sliderX = x + width / 2.0f - sliderWidth / 2.0f;
    int sliderY = y + height / 2.0f - sliderHeight / 2.0f + 15 * scale;
    g.addTransform(juce::AffineTransform::rotation(juce::MathConstants<float>::pi * (sliderPosProportional - 0.5f),
        x + width / 2.0f - 2 * scale, y + height / 2.0f + 20 * scale));
    g.drawImage(knobSlider, sliderX, sliderY, sliderWidth, sliderHeight, 0.0f, 0.0f,
        knobSlider.getWidth(), knobSlider.getHeight());

    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 40, 20);
    slider.setNumDecimalPlacesToDisplay(0);
}

juce::Font BlockLookAndFeel::getLabelFont(juce::Label& label)
{
    return juce::Font("Georgia", 20.0f, juce::Font::FontStyleFlags::plain);
}

juce::Label* BlockLookAndFeel::createSliderTextBox(juce::Slider& slider)
{
    juce::Label* label = new juce::Label();
    label->setJustificationType(juce::Justification::centred);
    return label;
}

void BlockLookAndFeel::drawToggleButton(juce::Graphics& g, juce::ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    float scale = (float)juce::jmin(button.getWidth(), button.getHeight()) / buttonDown.getWidth();
    juce::Image buttonImage = button.getToggleState() ? buttonDown : buttonUp;
    int width = buttonImage.getWidth() * scale;
    int height = buttonImage.getHeight() * scale;
    int x = button.getX() + button.getWidth() / 2.0f - width / 2.0f;
    int y = button.getY() + button.getHeight() / 2.0f - height / 2.0f;
    if (button.getToggleState()) {
        x += -10.0f * (scale / 2.0f);
        y += -10.0f * (scale / 2.0f);
    }
    g.drawImage(buttonImage, x, y, width, height, 0, 0, buttonImage.getWidth(), buttonImage.getHeight());
}
