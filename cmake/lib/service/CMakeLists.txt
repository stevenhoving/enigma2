set(SERVICE_PATH "${ENIGMA2_ROOT}/lib/service")

add_library(service STATIC
    ${SERVICE_PATH}/event.cpp
    ${SERVICE_PATH}/event.h
    ${SERVICE_PATH}/iservice.h
    ${SERVICE_PATH}/listboxservice.cpp
    ${SERVICE_PATH}/listboxservice.h
    ${SERVICE_PATH}/service.cpp
    ${SERVICE_PATH}/service.h
    ${SERVICE_PATH}/servicedvb.cpp
    ${SERVICE_PATH}/servicedvb.h
    ${SERVICE_PATH}/servicedvbrecord.cpp
    ${SERVICE_PATH}/servicedvbrecord.h
    ${SERVICE_PATH}/servicedvbstream.cpp
    ${SERVICE_PATH}/servicedvbstream.h
    # if we have dvd support
    #${SERVICE_PATH}/servicedvd.cpp
    #${SERVICE_PATH}/servicedvd.h
    ${SERVICE_PATH}/servicefs.cpp
    ${SERVICE_PATH}/servicefs.h
    ${SERVICE_PATH}/servicehdmi.cpp
    ${SERVICE_PATH}/servicehdmi.h
    ${SERVICE_PATH}/servicem2ts.cpp
    ${SERVICE_PATH}/servicem2ts.h
    ${SERVICE_PATH}/servicepeer.cpp
    ${SERVICE_PATH}/servicepeer.h
    ${SERVICE_PATH}/servicets.cpp
    ${SERVICE_PATH}/servicets.h
    ${SERVICE_PATH}/servicewebts.cpp
    ${SERVICE_PATH}/servicewebts.h
    # only when HAVE_LIBXINE is defined
    #${SERVICE_PATH}/servicexine.cpp
    #${SERVICE_PATH}/servicexine.h
)

target_include_directories(service
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(service
  PUBLIC
    # project deps
    python
    base

    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(service
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
