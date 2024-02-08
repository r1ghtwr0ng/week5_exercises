add_executable(RAII RAII.cpp FileManager.cpp)
target_include_directories(RAII PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(RAII PUBLIC cxx_std_17)
set_target_properties(RAII PROPERTIES CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)