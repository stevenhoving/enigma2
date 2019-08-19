set(MAIN_PATH "${ENIGMA2_ROOT}/main")

#WIN32
add_executable(main
    ${MAIN_PATH}/bsod.cpp #bsod is only supported on MIPSEL
    ${MAIN_PATH}/bsod.h
    ${MAIN_PATH}/version_info.cpp
    ${MAIN_PATH}/version_info.h
    ${MAIN_PATH}/enigma.cpp
)

target_include_directories(main
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
    ${MAIN_PATH}
)

target_link_libraries(main
  PUBLIC
    actions
    components
    base
    driver
    python
    network
    gdi
    gui
    nav
    service
    dvb
    dvb_ci
    mmi
    sigc-3.0
)

target_compile_definitions(main
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
