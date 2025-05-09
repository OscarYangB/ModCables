/*
  ==============================================================================

    BlockComponent.cpp
    Created: 9 May 2025 12:23:49pm
    Author:  Oscar

  ==============================================================================
*/

#include "BlockComponent.h"

BlockComponent::BlockComponent()
{
}

void BlockComponent::mouseDown(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        refreshMouseDragAnchor();
    }
}

void BlockComponent::mouseDrag(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        currentPoint = anchorPoint + getMouseXYRelative() + getPosition() - dragStart;
    }
}

void BlockComponent::mouseUp(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        refreshMouseDragAnchor();
    }
}

void BlockComponent::refreshMouseDragAnchor()
{
    dragStart = getMouseXYRelative() + getPosition();
    anchorPoint = currentPoint;
}

void BlockComponent::setBlockBounds(int x, int y, int w, int h)
{
    setBounds(x + currentPoint.x, y + currentPoint.y, w, h);
}

void BlockComponent::setLocation(juce::Point<int> newLocation)
{
    currentPoint = newLocation;
}
