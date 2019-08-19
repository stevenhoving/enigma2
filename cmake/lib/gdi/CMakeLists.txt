set(GDI_PATH "${ENIGMA2_ROOT}/lib/gdi")

add_library(gdi STATIC
    # enable when we build on broadcom platform
    ${GDI_PATH}/accel.cpp
    ${GDI_PATH}/accel.h
    #${GDI_PATH}/bcm.cpp

    ${GDI_PATH}/compositing.cpp
    ${GDI_PATH}/compositing.h
    ${GDI_PATH}/epng.cpp
    ${GDI_PATH}/epng.h
    ${GDI_PATH}/epoint.h
    ${GDI_PATH}/erect.cpp
    ${GDI_PATH}/erect.h
    ${GDI_PATH}/esize.h

    # direct framebuffer access?
    ${GDI_PATH}/fb.cpp
    ${GDI_PATH}/fb.h

    # framebuffer for LCD
    ${GDI_PATH}/fblcd.cpp
    ${GDI_PATH}/fblcd.h

    ${GDI_PATH}/font.cpp
    ${GDI_PATH}/font.h
    ${GDI_PATH}/font_arabic.cpp
    ${GDI_PATH}/gfbdc.cpp
    ${GDI_PATH}/gfbdc.h
    ${GDI_PATH}/gfont.cpp
    ${GDI_PATH}/gfont.h
    ${GDI_PATH}/glcddc.cpp
    ${GDI_PATH}/glcddc.h
    ${GDI_PATH}/gmaindc.cpp
    ${GDI_PATH}/gmaindc.h
    ${GDI_PATH}/gpixmap.cpp
    ${GDI_PATH}/gpixmap.h
    ${GDI_PATH}/grc.cpp
    ${GDI_PATH}/grc.h
    # enable if we have a hw lcd
    ${GDI_PATH}/lcd.cpp
    ${GDI_PATH}/lcd.h
    ${GDI_PATH}/picexif.cpp
    ${GDI_PATH}/picexif.h
    ${GDI_PATH}/picload.cpp
    ${GDI_PATH}/picload.h
    ${GDI_PATH}/pixmapcache.cpp
    ${GDI_PATH}/pixmapcache.h
    ${GDI_PATH}/region.cpp
    ${GDI_PATH}/region.h
    ${GDI_PATH}/sdl.cpp
    ${GDI_PATH}/sdl.h
)

target_include_directories(gdi
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
)

target_link_libraries(gdi
  PUBLIC
    # project deps
    base

    # library deps
    sigc-3.0
    freetype
    png_static
    turbojpeg-static
    libfribidid
    sdl2
    giflib
)

target_compile_definitions(gdi
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
