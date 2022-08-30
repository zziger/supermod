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

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.cpp" "src/proxy/dinput8.def")
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui)
set(IMGUI_DX8_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui-dx8)
set(IMGUI_FILES
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
    ${IMGUI_DX8_DIR}/imgui_impl_dx8.cpp
)

if(WIN32 AND (MSVC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_definitions(/MT)
endif()

add_library(${TARGET_NAME} SHARED "${PROJECT_SOURCE_FILES}" "${IMGUI_FILES}")
# add_executable(${TARGET_NAME} "${PROJECT_SOURCE_FILES}")
target_compile_definitions(${TARGET_NAME} PRIVATE ${DEFS} )
include_directories(${TARGET_NAME} PRIVATE "src" "src/thirdparty" "libs" "libs/imgui" "src/thirdparty/directx")
target_link_libraries(${TARGET_NAME} ${PROJECT_SOURCE_DIR}/libs/minhook.lib)