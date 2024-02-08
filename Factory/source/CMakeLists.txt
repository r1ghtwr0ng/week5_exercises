add_executable(Factory Factory.cpp UniversityMembers.cpp)
target_include_directories(Factory PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(Factory PUBLIC cxx_std_17)
set_target_properties(Factory PROPERTIES CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)