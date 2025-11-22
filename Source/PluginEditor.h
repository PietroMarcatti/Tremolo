/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TremoloAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TremoloAudioProcessorEditor (TremoloAudioProcessor&);
    ~TremoloAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TremoloAudioProcessor& audioProcessor;
    juce::Slider rateSlider, depthSlider, shapeSlider, envSlider;
    juce::ToggleButton activeBtn;
    juce::Label rateLabel, depthLabel, shapeLabel, envLabel;

    // Attachments (The Glue)
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

    std::unique_ptr<SliderAttachment> rateAtt, depthAtt, shapeAtt, envAtt;
    std::unique_ptr<ButtonAttachment> activeAtt;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
