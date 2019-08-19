set(MMI_PATH "${ENIGMA2_ROOT}/lib/mmi")

add_library(mmi STATIC
    ${MMI_PATH}/mmi_ui.cpp
    ${MMI_PATH}/mmi_ui.h
)

target_include_directories(mmi
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(mmi
  PUBLIC
    # project deps
    base
    python

    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    #freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(mmi
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
