set(DRIVER_PATH "${ENIGMA2_ROOT}/lib/driver")

add_library(driver STATIC
    ${DRIVER_PATH}/avswitch.cpp
    ${DRIVER_PATH}/avswitch.h
    ${DRIVER_PATH}/etimezone.cpp
    ${DRIVER_PATH}/etimezone.h
    ${DRIVER_PATH}/hdmi_cec.cpp
    ${DRIVER_PATH}/hdmi_cec.h
    ${DRIVER_PATH}/input_fake.h
    ${DRIVER_PATH}/linux-uapi-cec.h
    ${DRIVER_PATH}/misc_options.cpp
    ${DRIVER_PATH}/misc_options.h
    ${DRIVER_PATH}/rc.cpp
    ${DRIVER_PATH}/rc.h
    #${DRIVER_PATH}/rcconsole.cpp
    #${DRIVER_PATH}/rcconsole.h
    ${DRIVER_PATH}/rcdbox.h
    #${DRIVER_PATH}/rcdreambox2.cpp
    #${DRIVER_PATH}/rcdreambox2.h
    ${DRIVER_PATH}/rcinput.cpp
    ${DRIVER_PATH}/rcinput.h
    ${DRIVER_PATH}/rcinput_swig.h
    ${DRIVER_PATH}/rcsdl.cpp
    ${DRIVER_PATH}/rcsdl.h
    ${DRIVER_PATH}/rfmod.cpp
    ${DRIVER_PATH}/rfmod.h
)

target_include_directories(driver
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(driver
  PUBLIC
    # project deps
    base
    python

    # library deps
    sigc-3.0
)

target_compile_definitions(driver
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
