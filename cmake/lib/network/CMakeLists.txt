set(NETWORK_PATH "${ENIGMA2_ROOT}/lib/network")

add_library(network STATIC
    ${NETWORK_PATH}/serversocket.cpp
    ${NETWORK_PATH}/serversocket.h
    ${NETWORK_PATH}/socket.cpp
    ${NETWORK_PATH}/socket.h
    ${NETWORK_PATH}/xmlrpc.cpp
    ${NETWORK_PATH}/xmlrpc.h
)

target_include_directories(network
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(network
  PUBLIC
    # project deps
    base
    python
    xml2
    # library deps
    sigc-3.0
    libdvbsicpp # depends on dvb target
    #freetype # is it correct that serivce depends on freetype?
)

target_compile_definitions(network
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
    DISABLE_NETWORK
)
