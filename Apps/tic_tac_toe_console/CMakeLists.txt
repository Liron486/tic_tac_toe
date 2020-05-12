project(tic_tac_toe_console VERSION 0.1)

set (TargetName ${PROJECT_NAME})

juce_add_console_app(${TargetName} PRODUCT_NAME "Tic Tac Toe")
juce_generate_juce_header(${TargetName})

target_sources(${TargetName} PRIVATE 
    Source/configuration_gui_console.cpp
    Source/gui_console.cpp
    Source/Tic_Tac_Toe.cpp)

target_include_directories (${TargetName} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Game/Tic Tac Toe")

target_compile_definitions(${TargetName} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0)

target_link_libraries(${TargetName} PRIVATE juce::juce_core TicTacToe_Lib)
