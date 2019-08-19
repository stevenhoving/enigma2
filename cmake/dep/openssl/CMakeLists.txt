add_library(openssl INTERFACE IMPORTED GLOBAL)

target_include_directories(openssl
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/x64/include/
)

target_link_libraries(openssl
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/x64/lib/libcrypto.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/x64/lib/libssl.lib
)
