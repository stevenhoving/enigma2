
set(BASE_PATH "${ENIGMA2_ROOT}/lib/base")

set(BASE_EXEC_PATH "D:/dev/enigma2/bin")

set(prefix "")
set(exec_prefix "")
set(bindir "${BASE_EXEC_PATH}/bin")
set(sbindir "${BASE_EXEC_PATH}/sbin")
set(libexecdir "${BASE_EXEC_PATH}/libexec")
set(datarootdir "${BASE_EXEC_PATH}/dataroot")
set(datadir "${BASE_EXEC_PATH}/data")
set(sysconfdir "${BASE_EXEC_PATH}/sysconf")
set(sharedstatedir "${BASE_EXEC_PATH}/sharedstate")
set(localstatedir "${BASE_EXEC_PATH}/localstate")
set(libdir "${BASE_EXEC_PATH}/lib")
set(localedir "${BASE_EXEC_PATH}/locale")

#configure_file(
#    ${BASE_PATH}/eenv.cpp.in
#    eenv.cpp @ONLY)

configure_file(
    ${BASE_PATH}/eenv_data.h.in
    eenv_data.h @ONLY)

set(BASE_SOURCE
    # generated
    ${PROJECT_BINARY_DIR}/lib/base/eenv_data.h
    ${BASE_PATH}/eenv.cpp
    ${BASE_PATH}/eenv.h

    ${BASE_PATH}/ebase.cpp
    ${BASE_PATH}/ebase.h
    ${BASE_PATH}/etimer.cpp
    ${BASE_PATH}/etimer.h
    ${BASE_PATH}/emainloop.cpp
    ${BASE_PATH}/emainloop.h
    ${BASE_PATH}/esocketnotifier.cpp
    ${BASE_PATH}/esocketnotifier.h

    # utils
    ${BASE_PATH}/eerror.cpp
    ${BASE_PATH}/eerror.h
    ${BASE_PATH}/elock.cpp
    ${BASE_PATH}/elock.h
    ${BASE_PATH}/eptrlist.h
    ${BASE_PATH}/etime.h
)


add_library(base STATIC
    ${BASE_SOURCE}
    ${BASE_PATH}/benchmark.h
    ${BASE_PATH}/big5.h
    ${BASE_PATH}/buffer.cpp
    ${BASE_PATH}/buffer.h
    ${BASE_PATH}/cachedtssource.cpp
    ${BASE_PATH}/cachedtssource.h
    ${BASE_PATH}/cfile.cpp
    ${BASE_PATH}/cfile.h
    ${BASE_PATH}/connection.cpp
    ${BASE_PATH}/console.cpp
    ${BASE_PATH}/console.h
    ${BASE_PATH}/e2avahi.cpp
    ${BASE_PATH}/e2avahi.h

    ${BASE_PATH}/encoding.cpp
    ${BASE_PATH}/encoding.h
    
    ${BASE_PATH}/estring.cpp
    ${BASE_PATH}/estring.h
    ${BASE_PATH}/freesatv2.cpp
    ${BASE_PATH}/freesatv2.h
    ${BASE_PATH}/gb18030.h
    ${BASE_PATH}/httpsstream.cpp
    ${BASE_PATH}/httpsstream.h
    ${BASE_PATH}/httpstream.cpp
    ${BASE_PATH}/httpstream.h
    ${BASE_PATH}/huffman.cpp
    ${BASE_PATH}/huffman.h
    ${BASE_PATH}/i18n.h
    ${BASE_PATH}/init.cpp
    ${BASE_PATH}/init.h
    ${BASE_PATH}/init_num.h
    ${BASE_PATH}/ioprio.cpp
    ${BASE_PATH}/ioprio.h
    ${BASE_PATH}/itssource.h
    ${BASE_PATH}/message.cpp
    ${BASE_PATH}/message.h
    ${BASE_PATH}/nconfig.cpp
    ${BASE_PATH}/nconfig.h
    ${BASE_PATH}/object.h
    ${BASE_PATH}/rawfile.cpp
    ${BASE_PATH}/rawfile.h
    ${BASE_PATH}/ringbuffer.h
    ${BASE_PATH}/smartptr.cpp
    ${BASE_PATH}/smartptr.h
    ${BASE_PATH}/thread.cpp
    ${BASE_PATH}/thread.h
    ${BASE_PATH}/wrappers.cpp
    ${BASE_PATH}/wrappers.h
    ${BASE_PATH}/base64.cpp
    ${BASE_PATH}/base64.h
)

source_group("base" FILES
    ${BASE_SOURCE}
)


target_include_directories(base
  PUBLIC
    ${ENIGMA2_ROOT}
    ${ENIGMA2_ROOT}/include
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(base
  PUBLIC
    python
    sigc-3.0
    openssl
    fixup::fixup
    asio
)

target_compile_definitions(base
  PRIVATE
    _CRT_NONSTDC_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
)
