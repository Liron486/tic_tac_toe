cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)

project(LironProjects)

option(JUCE_BUILD_EXAMPLES "" ON)

#adding my own custom git functions, to save some boilerplate::
include (CMake/GitFunctions.cmake)

#calling my custom function to grab JUCE 6 from git:
update_from_git(juce "https://github.com/juce-framework/juce" develop)

#adding juce as a subdirectory:
add_subdirectory(${juce_SOURCE_DIR})

add_subdirectory(Apps)
add_subdirectory(Plugins)
