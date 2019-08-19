set(DVB_CI_PATH "${ENIGMA2_ROOT}/lib/dvb_ci")

add_library(dvb_ci STATIC
    ${DVB_CI_PATH}/dvbci.cpp
    ${DVB_CI_PATH}/dvbci.h
    ${DVB_CI_PATH}/dvbci_appmgr.cpp
    ${DVB_CI_PATH}/dvbci_appmgr.h
    ${DVB_CI_PATH}/dvbci_camgr.cpp
    ${DVB_CI_PATH}/dvbci_camgr.h
    ${DVB_CI_PATH}/dvbci_datetimemgr.cpp
    ${DVB_CI_PATH}/dvbci_datetimemgr.h
    ${DVB_CI_PATH}/dvbci_mmi.cpp
    ${DVB_CI_PATH}/dvbci_mmi.h
    ${DVB_CI_PATH}/dvbci_resmgr.cpp
    ${DVB_CI_PATH}/dvbci_resmgr.h
    ${DVB_CI_PATH}/dvbci_session.cpp
    ${DVB_CI_PATH}/dvbci_session.h
    ${DVB_CI_PATH}/dvbci_ui.cpp
    ${DVB_CI_PATH}/dvbci_ui.h
)

target_include_directories(dvb_ci
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(dvb_ci
  PUBLIC
    # project deps
    base
    python

    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    #freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(dvb_ci
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
