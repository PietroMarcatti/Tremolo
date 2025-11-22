/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    auto setupSlider = [this](juce::Slider& s) {
        s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
        addAndMakeVisible(s);
    };

    setupSlider(rateSlider);
    setupSlider(depthSlider);
    setupSlider(shapeSlider);
    setupSlider(envSlider);

    // Setup the button
    activeBtn.setButtonText("Activate");
    addAndMakeVisible(activeBtn);

    rateAtt = std::make_unique<SliderAttachment>(audioProcessor.apvts, "RATE", rateSlider);
    depthAtt = std::make_unique<SliderAttachment>(audioProcessor.apvts, "DEPTH", depthSlider);
    shapeAtt = std::make_unique<SliderAttachment>(audioProcessor.apvts, "SHAPE", shapeSlider);
    envAtt = std::make_unique<SliderAttachment>(audioProcessor.apvts, "ENV", envSlider);

    auto setupLabel = [this](juce::Label& lbl, juce::Slider& s, juce::String text) {
        lbl.setText(text, juce::dontSendNotification);
        lbl.setJustificationType(juce::Justification::centred);
        lbl.attachToComponent(&s, false);
        addAndMakeVisible(lbl);
    };

    setupLabel(rateLabel, rateSlider, "Rate");
    setupLabel(depthLabel, depthSlider, "Depth");
    setupLabel(shapeLabel, shapeSlider, "Shape");
    setupLabel(envLabel, envSlider, "Envelope");

    activeAtt = std::make_unique<ButtonAttachment>(audioProcessor.apvts, "ACTIVE", activeBtn);

    setSize (500, 300);
}

TremoloAudioProcessorEditor::~TremoloAudioProcessorEditor()
{
}

//==============================================================================
void TremoloAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
}

void TremoloAudioProcessorEditor::resized()
{
    int knobSize = 100;
    int yPos = 120;

    rateSlider.setBounds(20, yPos, knobSize, knobSize);
    depthSlider.setBounds(130, yPos, knobSize, knobSize);
    shapeSlider.setBounds(240, yPos, knobSize, knobSize);
    envSlider.setBounds(350, yPos, knobSize, knobSize);

    activeBtn.setBounds(20, 40, 100, 30);
}
