# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.22)
include(CMakePrintHelpers)
include(FetchContent)

FetchContent_Declare(
    cmake_scripts                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:kodezine/cmake_scripts.git
    GIT_TAG         ${GITHUB_BRANCH_TOOLCHAIN}
    EXCLUDE_FROM_ALL
)

# pre-fetch the toolchain repository as the first job before project configuration
FetchContent_GetProperties(cmake_scripts)

if(NOT cmake_scripts_POPULATED)
    FetchContent_MakeAvailable(cmake_scripts)
endif()

project(
    nucleo-f031k6
    VERSION     0.0.1
    LANGUAGES   C ASM CXX
    DESCRIPTION "Hardware Abstraction Layer for STM32CubeXX based project"
)

if (NOT DEFINED ARMCMSIS_DEVICE)
    string (TOLOWER ${STM32_DEVICE} ARMCMSIS_DEVICE)
endif ()

configure_file(${cmake_scripts_SOURCE_DIR}/frameworks/unity/target/targetbasedincludes.txt ${CMAKE_SOURCE_DIR}/src/targetbasedincludes.h @ONLY NEWLINE_STYLE UNIX)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src/main.c
        ${cmake_scripts_SOURCE_DIR}/frameworks/unity/target/vectors.c
)
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        ${STM32_DEVICE}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${cmake_scripts_SOURCE_DIR}/frameworks/unity/target
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/cubemx/Core/Inc
    ${cubemx_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F0xx/Include
    ${cubemx_SOURCE_DIR}/Drivers/CMSIS/Include
    ${cmsis_v5_SOURCE_DIR}/Device/ARM/ARMCM0/Include
    ${cubemx_SOURCE_DIR}/Drivers/STM32F0xx_HAL_Driver/Inc
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        stm32cubemx # uses cmsis from above
        segger_rtt
        CMSISDSP
)
set(${PROJECT_NAME}_LLVM_LINKER_SCRIPT "llvm.ld")
set(${PROJECT_NAME}_LLVM_LINKER_PATH "${CMAKE_SOURCE_DIR}")
setTargetCompileOptions(PROJECT_NAME)
setTargetLinkOptions(PROJECT_NAME)
