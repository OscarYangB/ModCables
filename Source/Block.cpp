/*
  ==============================================================================

    Block.cpp
    Created: 9 May 2025 12:23:49pm
    Author:  Oscar

  ==============================================================================
*/

#include "Block.h"

Block::Block()
{
}

void Block::mouseDown(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        refreshMouseDragAnchor();
    }
}

void Block::mouseDrag(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        currentPoint = anchorPoint + getMouseXYRelative() + getPosition() - dragStart;
    }
}

void Block::mouseUp(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        refreshMouseDragAnchor();
    }
}

void Block::refreshMouseDragAnchor()
{
    dragStart = getMouseXYRelative() + getPosition();
    anchorPoint = currentPoint;
}

void Block::setBlockBounds(int x, int y, int w, int h)
{
    setBounds(x + currentPoint.x, y + currentPoint.y, w, h);
}
