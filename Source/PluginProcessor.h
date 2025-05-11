/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/

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

    std::vector<int> amplitudeModSources;
    std::vector<int> pitchModSources;
    std::vector<int> phaseModSources;

    float time = 0.f;

    float evaluate(float sampleRate, float timeElapsed, bool released) 
    {
        float value = 0.f;

        switch (type) 
        {
        case SIN:
            value = sin(440 * 2 * juce::float_Pi * time);
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

        time += 1.f / sampleRate;
        
        value *= volume;

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

class ModCablesAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    ModCablesAudioProcessor();
    ~ModCablesAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    std::vector<OscillatorParams*> oscillators = std::vector<OscillatorParams*>();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModCablesAudioProcessor)
};
