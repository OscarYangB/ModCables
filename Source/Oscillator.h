#pragma once

#include <JuceHeader.h>
#include "BlockLookAndFeel.h"
#include "IconButton.h"
#include "BlockComponent.h"
#include "Connector.h"

float inline lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

enum OscillatorType
{
    SIN,
    SQUARE,
    TRIANGLE,
    SAW
};

struct OscillatorParams;

class Oscillator : public BlockComponent, juce::Button::Listener, juce::Slider::Listener
{
public:
	Oscillator(OscillatorParams* newParams);
	~Oscillator();

	void paint(juce::Graphics&) override;

	juce::Label name;

	void buttonClicked(juce::Button*) override;
	void buttonStateChanged(juce::Button* button) override;
	void sliderValueChanged(juce::Slider* slider) override;

	juce::Slider attack;
	juce::Slider decay;
	juce::Slider sustain;
	juce::Slider release;

	IconButton sin = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	IconButton square = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Square_png, BinaryData::Square_pngSize));
	IconButton triangle = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Triangle_png, BinaryData::Triangle_pngSize));
	IconButton saw = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Saw_png, BinaryData::Saw_pngSize));

	juce::Slider volume;
	juce::Slider pitch;
	IconButton keyTrack = IconButton(juce::ImageFileFormat::loadFrom(BinaryData::Sin_png, BinaryData::Sin_pngSize));
	juce::Slider phase;

	void updateOscillatorParams();
	void addConnectedOscillator(Connector* connector, Oscillator* oscillator);
	OscillatorParams* getOscillatorParams();

private:
	juce::Image backgroundImage = juce::ImageFileFormat::loadFrom(BinaryData::Background_png, BinaryData::Background_pngSize);
	
	juce::Label volumeLabel;
	juce::Label pitchLabel;
	juce::Label phaseLabel;

	juce::Label attackLabel;
	juce::Label decayLabel;
	juce::Label sustainLabel;
	juce::Label releaseLabel;

	Connector volumeMod = Connector(AM, this);
	Connector pitchMod = Connector(FM, this);
	Connector phaseMod = Connector(PM, this);
	Connector output = Connector(OUT, this);

	OscillatorParams* params;
};

struct OscillatorParams
{
    float volume;
    float pitch;
    float phase;

    bool keyTrack;

    float attack;
    float decay;
    float sustain;
    float release;

    OscillatorType type;

    std::vector<Oscillator*> amplitudeModSources = std::vector<Oscillator*>();
    std::vector<Oscillator*> pitchModSources = std::vector<Oscillator*>();
    std::vector<Oscillator*> phaseModSources = std::vector<Oscillator*>();

    float time = 0.f; // 0 to 2pi
    
    float evaluate(float sampleRate, float timeElapsed, bool released, bool progressTime, float frequency)
    {
        constexpr float twoPi = 2.f * juce::float_Pi;
        
        float amplitude = 0.2f * volume;
        frequency *= powf(2, pitch / 100.f);

        float phaseMod = phase;

        for (int i = 0; i < pitchModSources.size(); i++) {
            float mod = 5 * pitchModSources[i]->getOscillatorParams()->evaluate(sampleRate, timeElapsed, released, false, frequency);
            frequency *= (1.f + mod);
        }

        for (int i = 0; i < amplitudeModSources.size(); i++) {
            float mod = amplitudeModSources[i]->getOscillatorParams()->evaluate(sampleRate, timeElapsed, released, false, frequency);
            amplitude *= 1.f + mod;
        }

        for (int i = 0; i < phaseModSources.size(); i++) {
            float mod = phaseModSources[i]->getOscillatorParams()->evaluate(sampleRate, timeElapsed, released, false, frequency);
            phase += mod * twoPi;
        }

        float value = 0.f;
                        
        switch (type)
        {
        case SIN:
            value = amplitude * sin(time + juce::degreesToRadians(phaseMod));
            break;
        case SQUARE:
            //value = ti(time);
            break;
        case TRIANGLE:
            //value = sinf(time);
            break;
        case SAW:
            //value = sinf(time);
            break;
        }
    
        if (progressTime) {
            time += (frequency * twoPi) / sampleRate;

            if (time > twoPi) {
                time -= twoPi;
            }
        }
        
        if (!released)
        {
            if (timeElapsed < attack)
            {
                value *= timeElapsed / attack;
            }
            else if (timeElapsed < attack + decay)
            {
                value *= lerp(1.f, sustain, (timeElapsed - attack) / decay);
            }
            else
            {
                value *= sustain;
            }
        }
        else
        {
            value *= 1 - (timeElapsed / release);
        }

        return value;
    }

};

