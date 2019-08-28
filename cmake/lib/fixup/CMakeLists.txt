#add_library(fixup INTERFACE)
#add_library(fixup::fixup ALIAS fixup)

#target_include_directories(fixup
#  INTERFACE
#    .
#)

add_library(fixup STATIC
    aio.h
    byteswap.h
    compat_wordex.cpp
    getline.h
    gettime.h
    gettimeofday.h
    memrchr.h
    netdb.h
    poll.h
    portable_endian.h
    strings.h
    unistd.h
    wordexp.h
)

target_include_directories(fixup
  PUBLIC
    .
)

add_library(fixup::fixup ALIAS fixup)

set_target_properties(fixup PROPERTIES FOLDER "Fixup")

#target_include_directories(
#    spdlog
#    INTERFACE
#    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
#    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
#)