# ---- Name of test target ----

set(TEST_TARGET ${TARGET_LIB}_test)

# ---- Test dependencies ----

CPMAddPackage(
    NAME cctest
    GITHUB_REPOSITORY ccup/cctest
    GIT_TAG master
)

# ---- Source files of test ----

file(GLOB_RECURSE SOURCES 
    "*.c" "*.C" "*.cc" "*.CC" "*.cpp" "*.CPP" "*.c++")

# ---- Define test target ----

add_executable(${TEST_TARGET} ${SOURCES})

target_include_directories(${TEST_TARGET}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
            ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${TEST_TARGET} PRIVATE ${TARGET_LIB} cctest_main )

set_target_properties(${TEST_TARGET} PROPERTIES CXX_STANDARD 14)
target_compile_definitions(${TEST_TARGET} PRIVATE CUSTOMER_LOG)

# ---- Code coverage ----

if(ENABLE_TEST_COVERAGE)
    target_compile_options(${TEST_TARGET} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(${TEST_TARGET} PUBLIC -fprofile-arcs -ftest-coverage)
endif()

# ---- Add test for CTest ----

include(CTest)
enable_testing()
add_test(NAME test COMMAND ${TEST_TARGET})
