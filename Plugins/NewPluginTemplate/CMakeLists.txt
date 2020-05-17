project(NewPluginTemplate VERSION 0.0.1)

set (BaseTargetName NewPluginTemplate)

juce_add_plugin("${BaseTargetName}"
        COMPANY_NAME "Gal Ben Naim"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT TRUE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE GLbn
        PLUGIN_CODE Dem0
        FORMATS AU VST3 Standalone
        PRODUCT_NAME "Audio Plugin Example")

juce_generate_juce_header(${BaseTargetName})

target_sources(${BaseTargetName} PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp)

target_compile_definitions(${BaseTargetName}
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(${BaseTargetName} PRIVATE
        juce::juce_audio_utils)
