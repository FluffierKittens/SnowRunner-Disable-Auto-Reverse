link_directories(DisableAutoReverse lib)

add_library (DisableAutoReverse SHARED "DisableAutoReverse.cpp" "Logging.cpp" "version.rc")

target_link_libraries(DisableAutoReverse detours)