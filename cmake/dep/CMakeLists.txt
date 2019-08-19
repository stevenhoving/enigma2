#set(BUILD_STATIC_LIBS ON)

add_subdirectory(libsigcplusplus)
add_subdirectory(openssl)
add_subdirectory(zlib)

# libpng
set(PNG_SHARED OFF CACHE BOOL "" FORCE)
set(PNG_TESTS OFF CACHE BOOL "" FORCE)
set(PNG_BUILD_ZLIB ON CACHE BOOL "" FORCE)
add_subdirectory(png)
add_subdirectory(libjpeg_turbo)

set(SKIP_INSTALL_LIBRARIES ON CACHE BOOL "" FORCE)
set(SKIP_INSTALL_ALL ON CACHE BOOL "" FORCE)
set(SKIP_INSTALL_HEADERS ON CACHE BOOL "" FORCE)

add_subdirectory(freetype2)
add_subdirectory(libdvbsi++)
add_subdirectory(googletest)


set_target_properties(sigc-3.0 PROPERTIES FOLDER "External/sigc-3.0")
set_target_properties(freetype PROPERTIES FOLDER "External/freetype")
set_target_properties(libdvbsicpp PROPERTIES FOLDER "External/libdvbsicpp")

# hack hack hack
add_library(libfribidid INTERFACE IMPORTED GLOBAL)
target_link_libraries(libfribidid
    INTERFACE
        D:/dev/enigma2/cmake/dep/fribidi/msvc/lib/x64/libfribidid.lib
)

target_include_directories(libfribidid
  INTERFACE
    D:/dev/enigma2/cmake/dep/fribidi/msvc/include
)

############ SDL2
add_library(sdl2 INTERFACE IMPORTED GLOBAL)
target_link_libraries(sdl2
    INTERFACE
        D:/dev/enigma2/cmake/dep/sdl2/lib64/SDL2.lib
)

target_include_directories(sdl2
  INTERFACE
    D:/dev/enigma2/cmake/dep/sdl2/include
)

############# libiconv
add_library(libiconv INTERFACE IMPORTED GLOBAL)
target_link_libraries(libiconv
    INTERFACE
        D:/dev/enigma2/cmake/dep/libiconv/lib64/libiconvStaticD.lib
)

target_include_directories(libiconv
  INTERFACE
    D:/dev/enigma2/cmake/dep/libiconv/include
)


add_subdirectory(libxml2)

#####################giflib

set(GIF_PATH
    "D:/dev/enigma2/cmake/dep/giflib/lib"
)
add_library(giflib
    ${GIF_PATH}/dgif_lib.c
    #${GIF_PATH}/egif_lib.c
    ${GIF_PATH}/gif_err.c
    ${GIF_PATH}/gif_font.c
    ${GIF_PATH}/gif_hash.c
    ${GIF_PATH}/gif_hash.h
    ${GIF_PATH}/gif_lib.h
    ${GIF_PATH}/gif_lib_private.h
    ${GIF_PATH}/gifalloc.c
    ${GIF_PATH}/openbsd-reallocarray.c
    ${GIF_PATH}/quantize.c
)
target_include_directories(giflib
  PUBLIC
    ${GIF_PATH}
)

set_target_properties(giflib PROPERTIES FOLDER "External/giflib")


#set(AVAHI_PATH
#    "D:/dev/enigma2/cmake/dep/avahi"
#)
#
#add_library(avahi_common
#    ${AVAHI_PATH}/avahi-common/address.c
#    ${AVAHI_PATH}/avahi-common/address.h
#    #${AVAHI_PATH}/avahi-common/alternative-test.c
#    ${AVAHI_PATH}/avahi-common/alternative.c
#    ${AVAHI_PATH}/avahi-common/alternative.h
#    ${AVAHI_PATH}/avahi-common/cdecl.h
#    ${AVAHI_PATH}/avahi-common/dbus-watch-glue.c
#    ${AVAHI_PATH}/avahi-common/dbus-watch-glue.h
#    ${AVAHI_PATH}/avahi-common/dbus.c
#    ${AVAHI_PATH}/avahi-common/dbus.h
#    ${AVAHI_PATH}/avahi-common/defs.h
#    #${AVAHI_PATH}/avahi-common/domain-test.c
#    ${AVAHI_PATH}/avahi-common/domain.c
#    ${AVAHI_PATH}/avahi-common/domain.h
#    ${AVAHI_PATH}/avahi-common/error.c
#    ${AVAHI_PATH}/avahi-common/error.h
#    ${AVAHI_PATH}/avahi-common/gccmacro.h
#    ${AVAHI_PATH}/avahi-common/i18n.c
#    ${AVAHI_PATH}/avahi-common/i18n.h
#    ${AVAHI_PATH}/avahi-common/llist.h
#    ${AVAHI_PATH}/avahi-common/malloc.c
#    ${AVAHI_PATH}/avahi-common/malloc.h
#    ${AVAHI_PATH}/avahi-common/rlist.c
#    ${AVAHI_PATH}/avahi-common/rlist.h
#    ${AVAHI_PATH}/avahi-common/simple-watch.c
#    ${AVAHI_PATH}/avahi-common/simple-watch.h
#    #${AVAHI_PATH}/avahi-common/strlst-test.c
#    ${AVAHI_PATH}/avahi-common/strlst.c
#    ${AVAHI_PATH}/avahi-common/strlst.h
#    ${AVAHI_PATH}/avahi-common/thread-watch.c
#    ${AVAHI_PATH}/avahi-common/thread-watch.h
#    #${AVAHI_PATH}/avahi-common/timeval-test.c
#    ${AVAHI_PATH}/avahi-common/timeval.c
#    ${AVAHI_PATH}/avahi-common/timeval.h
#    #${AVAHI_PATH}/avahi-common/utf8-test.c
#    ${AVAHI_PATH}/avahi-common/utf8.c
#    ${AVAHI_PATH}/avahi-common/utf8.h
#    #${AVAHI_PATH}/avahi-common/watch-test.c
#    ${AVAHI_PATH}/avahi-common/watch.h
#)
#
#target_include_directories(avahi_common
#  PUBLIC
#    ${AVAHI_PATH}
#    ${AVAHI_PATH}/avahi-common
#)
#
#add_library(avahi_client
#    ${AVAHI_PATH}/avahi-client/browser.c
#    #${AVAHI_PATH}/avahi-client/check-nss-test.c
#    ${AVAHI_PATH}/avahi-client/check-nss.c
#    #${AVAHI_PATH}/avahi-client/client-test.c
#    ${AVAHI_PATH}/avahi-client/client.c
#    ${AVAHI_PATH}/avahi-client/client.h
#    ${AVAHI_PATH}/avahi-client/entrygroup.c
#    ${AVAHI_PATH}/avahi-client/internal.h
#    ${AVAHI_PATH}/avahi-client/lookup.h
#    ${AVAHI_PATH}/avahi-client/publish.h
#    ${AVAHI_PATH}/avahi-client/resolver.c
#    #${AVAHI_PATH}/avahi-client/rr-test.c
#    #${AVAHI_PATH}/avahi-client/srv-test.c
#    #${AVAHI_PATH}/avahi-client/xdg-config-test.c
#    ${AVAHI_PATH}/avahi-client/xdg-config.c
#    ${AVAHI_PATH}/avahi-client/xdg-config.h
#)
#target_include_directories(avahi_client
#  PUBLIC
#    ${AVAHI_PATH}
#    ${AVAHI_PATH}/avahi-client
#)
#
#target_link_libraries(avahi_client
#    public
#        avahi_common
#)
#
#set_target_properties(avahi_client PROPERTIES FOLDER "External/avahi")
#set_target_properties(avahi_common PROPERTIES FOLDER "External/avahi")
