include(Unittests)

add_unit_test_suite(
    TARGET test_python
    SOURCES
        test_connection.cpp
    INCLUDES
        ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARIES python
    FOLDER tests/python
)