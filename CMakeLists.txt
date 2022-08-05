cmake_minimum_required (VERSION 3.8)

set(TARGET_NAME supercow-mod)

project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_GENERATOR_PLATFORM Win32)

if (NOT VERSION)
    set(VERSION manual_build)
endif()

message("Building version " ${VERSION})

set(DEFS
    # Compliation
    -DCXX_COMPILER_ID="${CMAKE_CXX_COMPILER_ID}"
    -D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

    # Platform
    -DUNICODE
    -D_UNICODE
    -DVERSION="${VERSION}"
)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.cpp" "src/proxy/msimg32.def")

if(WIN32 AND (MSVC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_definitions(/MT)
endif()

add_library(${TARGET_NAME} SHARED "${PROJECT_SOURCE_FILES}")
# add_executable(${TARGET_NAME} "${PROJECT_SOURCE_FILES}")
target_compile_definitions(${TARGET_NAME} PRIVATE ${DEFS} )
include_directories(${TARGET_NAME} PRIVATE "src" "src/thirdparty")
target_link_libraries(${TARGET_NAME} ${PROJECT_SOURCE_DIR}/libs/minhook.lib)