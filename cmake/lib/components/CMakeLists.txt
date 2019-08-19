set(COMPONENTS_PATH "${ENIGMA2_ROOT}/lib/components")

add_library(components STATIC
    ${COMPONENTS_PATH}/file_eraser.cpp
    ${COMPONENTS_PATH}/file_eraser.h
    ${COMPONENTS_PATH}/scan.cpp
    ${COMPONENTS_PATH}/scan.h
    ${COMPONENTS_PATH}/tuxtxtapp.cpp
    ${COMPONENTS_PATH}/tuxtxtapp.h
)

target_include_directories(components
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(components
  PUBLIC
    # project deps
    base
    python

    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    #freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(components
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
