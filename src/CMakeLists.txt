# ---- Src dependencies ----

CPMAddPackage(
    NAME mcl
    GITHUB_REPOSITORY ccup/mcl
    GIT_TAG master
    OPTIONS "ENABLE_TEST off"
)

CPMAddPackage(
    NAME alert-intf
    GITHUB_REPOSITORY joycode-bootcamp/alert-intf
    GIT_TAG master
)

CPMAddPackage(
    NAME clean-intf
    GITHUB_REPOSITORY joycode-bootcamp/clean-intf
    GIT_TAG master
)

# ---- Collect all src files except main.c ----

file(GLOB_RECURSE MAIN_FILE 
    "main.c"
)

file(GLOB_RECURSE SOURCES
    "*.c" "*.C" "*.cc" "*.CC" "*.cpp" "*.CPP" "*.c++"
)

list(REMOVE_ITEM SOURCES ${MAIN_FILE})

# ---- Define library target ----

if (SHARED)
    set(LIB_TYPE SHARED)
    set(CMAKE_C_VISIBILITY_PRESET hidden)
else()
    set(LIB_TYPE STATIC)
endif()

add_library(${TARGET_LIB} ${LIB_TYPE} ${SOURCES})

target_link_libraries(${TARGET_LIB} PUBLIC mcl alert-intf clean-intf)

target_include_directories(${TARGET_LIB}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/deps
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_compile_definitions(${TARGET_LIB} PRIVATE CUSTOMER_LOG)

# ---- Add executable target ----

if (EXECUTABLE)
    set(EXEC_TARGET ${TARGET_LIB}_service)
    add_executable(${EXEC_TARGET} ${MAIN_FILE})
    target_link_libraries(${EXEC_TARGET} PRIVATE ${TARGET_LIB})
endif()