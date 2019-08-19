find_package (Python2 COMPONENTS Development Interpreter)

#cmake_policy(SET CMP0078 "NEW")
find_package (swig REQUIRED)
include(UseSWIG)


set(PYTHON_PATH "${ENIGMA2_ROOT}/lib/python")

set(PYTHON_GEN_SOURCES
    ${PYTHON_PATH}/enigma_python.i
	${PYTHON_PATH}/python_service.i
	${PYTHON_PATH}/python_dvb.i
	${PYTHON_PATH}/python_base.i
	${PYTHON_PATH}/python_console.i
	${PYTHON_PATH}/python_pmt.i
	${PYTHON_PATH}/python_pcore.i
)

execute_process(
    COMMAND "${SWIG_EXECUTABLE}" -python -c++ -O -nortti -nothreads -I${ENIGMA2_ROOT}
        -MT ${PYTHON_PATH}/gen/enigma_python.cpp
        -MD
        -MF ${PYTHON_PATH}/dep/enigma_python.i.Tpo
        -o ${PYTHON_PATH}/gen/enigma_python.cpp
        ${PYTHON_PATH}/enigma_python.i
    OUTPUT_VARIABLE SWIG_CONSOLE_OUTPUT
)

#execute_process(
#    COMMAND "${Python2_EXECUTABLE}" "${ENIGMA2_ROOT}/lib/actions/parseactions.py" "include" ${ACTIONS_PARSE_LIST}
#    OUTPUT_VARIABLE ACTIONS_IDS_HEADER_1
#)

#swig -python -c++ -ID:/dev/enigma2/ -O -nortti -nothreads D:/dev/enigma2/lib/python/enigma_python.i
#swig -python -c++ -ID:/dev/enigma2/ -O -nortti -nothreads -o D:/dev/enigma2/lib/python/enigma_python.i.cpp D:/dev/enigma2/lib/python/enigma_python.i



#set_property(SOURCE ${PYTHON_PATH}/enigma_python.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_service.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_dvb.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_base.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_console.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_pmt.i PROPERTY CPLUSPLUS ON)
#set_property(SOURCE ${PYTHON_PATH}/python_pcore.i PROPERTY CPLUSPLUS ON)
#
## We should use SWIG_INCLUDE_DIRECTORIES
#include_directories(
#    ${PYTHON_INCLUDE_PATH}
#    ${ENIGMA2_ROOT}
#)
#
#set(CMAKE_SWIG_FLAGS
#    -O -nortti -nothreads -noproxy
#)
#
#swig_add_library(enigma
#  TYPE
#    MODULE
#  LANGUAGE
#    python
#  NO_PROXY
#  OUTFILE_DIR
#    ${PYTHON_PATH}/gen/
#  SOURCES
#    ${PYTHON_PATH}/enigma_python.i
#    ${PYTHON_PATH}/python_service.i
#    ${PYTHON_PATH}/python_dvb.i
#    ${PYTHON_PATH}/python_base.i
#    ${PYTHON_PATH}/python_console.i
#    ${PYTHON_PATH}/python_pmt.i
#    ${PYTHON_PATH}/python_pcore.i
#)

#swig_link_libraries(enigma enigma_python
#  ${PYTHON_LIBRARIES}
#  Python2::Python
#)





#execute_process(
#    COMMAND "${Python2_EXECUTABLE}" "${ENIGMA2_ROOT}/lib/actions/parseactions.py" "include" ${ACTIONS_PARSE_LIST}
#    OUTPUT_VARIABLE ACTIONS_IDS_HEADER_1
#)
#execute_process(
#    COMMAND "${Python2_EXECUTABLE}" "${ENIGMA2_ROOT}/lib/actions/parseactions.py" "parse" ${ACTIONS_PARSE_LIST}
#    OUTPUT_VARIABLE ACTIONS_IDS_HEADER_2
#)
#
#set(ACTIONS_IDS_HEADER "${ACTIONS_IDS_HEADER_1}${ACTIONS_IDS_HEADER_2}")
#
#file(WRITE "${ENIGMA2_ROOT}/lib/actions/actionids.h" "${ACTIONS_IDS_HEADER}")




add_library(python STATIC
    ${PYTHON_PATH}/connections.cpp
    ${PYTHON_PATH}/connections.h
    ${PYTHON_PATH}/python.cpp
    ${PYTHON_PATH}/python.h
    ${PYTHON_PATH}/python_helpers.cpp
    ${PYTHON_PATH}/python_helpers.h
    ${PYTHON_PATH}/pythonconfig.cpp
    ${PYTHON_PATH}/pythonconfig.h
    ${PYTHON_PATH}/swig.h

    # generated
    ${PYTHON_PATH}/gen/enigma_python.cpp
)

target_include_directories(python
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(python
  PUBLIC
    Python2::Python
    dvb
    gdi
    #freetype
    sigc-3.0
    fixup::fixup
)

target_compile_definitions(python
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
)

target_compile_options(python
  PUBLIC
    /wd5033
)


