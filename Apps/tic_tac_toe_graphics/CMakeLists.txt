project(TicTacToeGraphics VERSION 0.0.1)

set (TargetName ${PROJECT_NAME})

juce_add_gui_app(${TargetName} PRODUCT_NAME "Tic Tac Toe - Graphics")
juce_generate_juce_header(${TargetName})

target_sources(${TargetName} PRIVATE
        Source/Main.cpp
        Source/MainWindow.cpp
        Source/MainComponent.cpp
        Source/CellGui.cpp
        Source/BoardGui.cpp
        Source/Ex.cpp
        Source/GameFlowController.cpp
        Source/Circle.cpp
        Source/WelcomePage.cpp
        Source/ButtonLNF.cpp
        Source/Configuration/ConfigurationGui.cpp
        Source/Configuration/NumOfPlayersSection.cpp
        Source/Configuration/DifficultySection.cpp)

target_include_directories (${TargetName} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Game/Tic Tac Toe")

target_compile_definitions(${TargetName} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_PROJECT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_VERSION>")

target_link_libraries(${TargetName} PRIVATE juce::juce_gui_extra TicTacToe_Lib)
