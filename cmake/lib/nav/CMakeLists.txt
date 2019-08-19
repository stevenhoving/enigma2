set(NAV_PATH "${ENIGMA2_ROOT}/lib/nav")

add_library(nav STATIC
    ${NAV_PATH}/core.cpp
    ${NAV_PATH}/core.h
    ${NAV_PATH}/pcore.cpp
    ${NAV_PATH}/pcore.h
)

target_include_directories(nav
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(nav
  PUBLIC
    # project deps
    base
    python

    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    #freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(nav
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
