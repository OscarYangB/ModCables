/*
  ==============================================================================

    Connector.cpp
    Created: 15 May 2025 10:10:13am
    Author:  Oscar

  ==============================================================================
*/

#include "Connector.h"

Connector::Connector(ConnectorColour newColour)
{
    colour = newColour;

    if (colour == RED) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Red_png, BinaryData::EmptyConnector_Red_pngSize)));
    }
    else if (colour == YELLOW) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Yellow_png, BinaryData::EmptyConnector_Yellow_pngSize)));
    }
    else if (colour == BLUE) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_png, BinaryData::EmptyConnector_pngSize)));
    }
    else if (colour == GRAY) {
        image.setImage(juce::Image(juce::ImageFileFormat::loadFrom(BinaryData::EmptyConnector_Gray_png, BinaryData::EmptyConnector_Gray_pngSize)));
    }

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

void Connector::mouseDown(const juce::MouseEvent& event)
{
    if (colour == GRAY) {
        juce::Point<int> location = getScreenPosition() - getTopLevelComponent()->getScreenPosition();
        location += juce::Point<int>(getWidth() / 2.f, getHeight() / 2.f);
        draggingConnection = new BlockLink(location);
        getTopLevelComponent()->addAndMakeVisible(draggingConnection);
    }
}

void Connector::mouseUp(const juce::MouseEvent& event)
{
    delete draggingConnection;
    draggingConnection = nullptr;


    juce::Component* comp = juce::Desktop::getInstance().findComponentAt(event.getScreenPosition());
    
    if (comp != nullptr && typeid(*comp) == typeid(Connector) && comp != this) {
        juce::Logger::writeToLog("test");
    }

}

void Connector::paint(juce::Graphics& g)
{
    image.setBounds(0, 0, getWidth(), getHeight());
    
    if (draggingConnection != nullptr) {
        draggingConnection->setBounds(0, 0, 1000, 1000);
    }
}


