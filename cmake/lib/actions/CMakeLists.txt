find_package (Python2 COMPONENTS Interpreter)

file(GLOB ACTIONS_PARSE_LIST
    "${ENIGMA2_ROOT}/lib/gui/*.h"
)

execute_process(
    COMMAND "${Python2_EXECUTABLE}" "${ENIGMA2_ROOT}/lib/actions/parseactions.py" "include" ${ACTIONS_PARSE_LIST}
    OUTPUT_VARIABLE ACTIONS_IDS_HEADER_1
)
execute_process(
    COMMAND "${Python2_EXECUTABLE}" "${ENIGMA2_ROOT}/lib/actions/parseactions.py" "parse" ${ACTIONS_PARSE_LIST}
    OUTPUT_VARIABLE ACTIONS_IDS_HEADER_2
)

set(ACTIONS_IDS_HEADER "${ACTIONS_IDS_HEADER_1}${ACTIONS_IDS_HEADER_2}")

file(WRITE "${ENIGMA2_ROOT}/lib/actions/actionids.h" "${ACTIONS_IDS_HEADER}")

add_library(actions STATIC
    ${ENIGMA2_ROOT}/lib/actions/action.cpp
    ${ENIGMA2_ROOT}/lib/actions/action.h
    ${ENIGMA2_ROOT}/lib/actions/actionids.h
    ${ENIGMA2_ROOT}/lib/actions/parseactions.py
)

target_include_directories(actions
  PUBLIC
    ${ENIGMA2_ROOT}
)

target_link_libraries(actions
  PUBLIC
    base
)