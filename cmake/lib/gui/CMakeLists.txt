
set(GUI_PATH "${ENIGMA2_ROOT}/lib/gui")

add_library(gui STATIC
    ${GUI_PATH}/ebutton.cpp
    ${GUI_PATH}/ebutton.h
    ${GUI_PATH}/ecanvas.cpp
    ${GUI_PATH}/ecanvas.h
    ${GUI_PATH}/egauge.cpp
    ${GUI_PATH}/egauge.h
    ${GUI_PATH}/einput.cpp
    ${GUI_PATH}/einput.h
    ${GUI_PATH}/einputnumber.cpp
    ${GUI_PATH}/einputnumber.h
    ${GUI_PATH}/einputstring.cpp
    ${GUI_PATH}/einputstring.h
    ${GUI_PATH}/elabel.cpp
    ${GUI_PATH}/elabel.h
    ${GUI_PATH}/elistbox.cpp
    ${GUI_PATH}/elistbox.h
    ${GUI_PATH}/elistboxcontent.cpp
    ${GUI_PATH}/elistboxcontent.h
    ${GUI_PATH}/epixmap.cpp
    ${GUI_PATH}/epixmap.h
    ${GUI_PATH}/epositiongauge.cpp
    ${GUI_PATH}/epositiongauge.h
    ${GUI_PATH}/eslider.cpp
    ${GUI_PATH}/eslider.h
    ${GUI_PATH}/esubtitle.cpp
    ${GUI_PATH}/esubtitle.h
    ${GUI_PATH}/evideo.cpp
    ${GUI_PATH}/evideo.h
    ${GUI_PATH}/ewidget.cpp
    ${GUI_PATH}/ewidget.h
    ${GUI_PATH}/ewidgetanimation.cpp
    ${GUI_PATH}/ewidgetanimation.h
    ${GUI_PATH}/ewidgetdesktop.cpp
    ${GUI_PATH}/ewidgetdesktop.h
    ${GUI_PATH}/ewindow.cpp
    ${GUI_PATH}/ewindow.h
    ${GUI_PATH}/ewindowstyle.cpp
    ${GUI_PATH}/ewindowstyle.h
    ${GUI_PATH}/ewindowstyleskinned.cpp
    ${GUI_PATH}/ewindowstyleskinned.h
)

target_include_directories(gui
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(gui
  PUBLIC
    python
    sigc-3.0
    freetype
    libdvbsicpp
)

target_compile_definitions(gui
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
)
