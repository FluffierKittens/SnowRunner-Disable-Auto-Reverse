cmake_minimum_required (VERSION 3.8)

project (DisableAutoReverse VERSION 0.1.2 LANGUAGES CXX)

#Removing this test and trying a new combination earns you points for bravery
if(NOT MSVC OR NOT ${MSVC_VERSION} VERSION_EQUAL 1935)
  message(FATAL_ERROR "Project has only been tested on Visual Studio 17 (2022), with MSVC 19.35 compiler")
endif()

#Uncomment below line to compile a version without the debug console
#add_compile_definitions(DAR_NO_CONSOLE)

add_subdirectory(DLL)
add_subdirectory(Injector)
