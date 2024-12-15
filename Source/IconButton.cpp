/*
  ==============================================================================

    IconButton.cpp
    Created: 15 Dec 2024 2:26:08pm
    Author:  Oscar

  ==============================================================================
*/

#include "IconButton.h"

IconButton::IconButton(juce::Image newIcon)
{
    icon.setImage(newIcon);
    icon.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(button);
    addAndMakeVisible(icon);
}

IconButton::~IconButton()
{
}

void IconButton::paint(juce::Graphics& g)
{
    button.setBounds(0, 0, getWidth(), getHeight());
    float scale = (float) getWidth() / icon.getImage().getWidth();
    scale *= button.getToggleState() ? 0.32f : 0.36f;
    float width = icon.getImage().getWidth() * scale;
    float height = icon.getImage().getHeight() * scale;
    int x = round(getWidth() / 2.0f - width / 2.0f - 4.0f * (scale / 2.0f));
    int y = round(getHeight() / 2.0f - height / 2.0f - 4.0f * (scale / 2.0f));
    icon.setBounds(x, y, round(width), round(height));
}
