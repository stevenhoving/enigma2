cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0078 NEW)

project(enigma2)

list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake"
)

include(CTest)
enable_testing()

if(DEFINED MSVC)
    set(CMAKE_CXX_STANDARD 17)
    add_compile_options(/permissive-) # vs conformance mode.
    add_compile_options(/W0) # weak warnings
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

add_definitions(-DWIN32_LEAN_AND_MEAN)

###############################################################################

add_subdirectory(dep)

###############################################################################

# it goes something like this
get_filename_component(ENIGMA2_ROOT "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

add_subdirectory(lib)
add_subdirectory(main)

