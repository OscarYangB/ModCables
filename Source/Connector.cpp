/*
  ==============================================================================

    Connector.cpp
    Created: 15 May 2025 10:10:13am
    Author:  Oscar

  ==============================================================================
*/

#include "Connector.h"
#include "Oscillator.h"

Connector::Connector(ConnectorColour newColour, Oscillator* newOscillator) : Connector()
{
    colour = newColour;
    oscillator = newOscillator;

    if (colour == PM) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Red_png, BinaryData::EmptyConnector_Red_pngSize)));
    }
    else if (colour == AM) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Yellow_png, BinaryData::EmptyConnector_Yellow_pngSize)));
    }
    else if (colour == FM) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_png, BinaryData::EmptyConnector_pngSize)));
    }
    else if (colour == OUT) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Gray_png, BinaryData::EmptyConnector_Gray_pngSize)));
    }
}

Connector::Connector()
{
    image.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(image);

    startTimer(16);
}

void Connector::timerCallback()
{
    if (draggingConnection != nullptr) {
        repaint();
    }
}

Oscillator* Connector::getOscillator()
{
    return oscillator;
}

ConnectorColour Connector::getType()
{
    return colour;
}

void Connector::mouseDown(const juce::MouseEvent& event)
{
    if (colour == OUT) {
        juce::Point<int> location = getScreenPosition() - getTopLevelComponent()->getScreenPosition();
        location += juce::Point<int>(getWidth() / 2.f, getHeight() / 2.f);
        draggingConnection = new BlockLink(location);
        getTopLevelComponent()->addAndMakeVisible(draggingConnection);
    }
}

void Connector::mouseUp(const juce::MouseEvent& event)
{
    juce::Component* comp = juce::Desktop::getInstance().findComponentAt(event.getScreenPosition());
    
    if (comp != nullptr && typeid(*comp) == typeid(Connector) && comp != this) {
        Connector* connector = (Connector*)comp;
        connector->getOscillator()->addConnectedOscillator(connector, getOscillator());

        draggingConnection->isDragging = false;
    }
    else 
    {
        delete draggingConnection;
        draggingConnection = nullptr;
    }

}

void Connector::paint(juce::Graphics& g)
{
    image.setBounds(0, 0, getWidth(), getHeight());
    
    if (draggingConnection != nullptr) {
        draggingConnection->setBounds(0, 0, 1000, 1000);
    }
}


