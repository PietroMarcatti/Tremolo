cmake_minimum_required(VERSION 3.15)

# 1. PROJECT NAME
project(Tremolo VERSION 0.0.1)

# 2. IMPORT JUCE
# We assume JUCE is located in a folder next to the source, or downloaded dynamically.
add_subdirectory(JUCE)

# 3. DEFINE THE PLUGIN
juce_add_plugin(Tremolo
    COMPANY_NAME "TorDISCOsa"             # Change this
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE               # We need this for the Note trigger
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    # FORMATS VST3 AU                  # Build VST3 and AU (Mac format)
    FORMATS VST3
    PRODUCT_NAME "Tremolo")

# 4. LINK YOUR FILES
target_sources(Tremolo PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h)

juce_generate_juce_header(Tremolo)
target_include_directories(Tremolo PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/JuceLibraryCode")

# 5. LINK LIBRARIES
target_compile_definitions(Tremolo PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(Tremolo PRIVATE
    juce::juce_audio_utils
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags)