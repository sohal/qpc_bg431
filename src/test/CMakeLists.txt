cmake_minimum_required(VERSION 3.21)

# NOTE: Project name MUST match the test file name
project(
    ut_source
)

# Add test sources here ...
set(TEST_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/../source.c
)

# DO NOT ADD ANY-THING IN THE VARIABLE BELOW
set(TEST_INCLUDE_DIR
    ${CMAKE_CURRENT_LIST_DIR}/..
)

# Add optional include files here based on architecture ...
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm")
    set(OTHER_INCLUDE_DIR
        ${cmsis_SOURCE_DIR}/include/cmsis
    )

    set(${PROJECT_NAME}_LLVM_LINKER_SCRIPT "llvm.ld")
    set(${PROJECT_NAME}_LLVM_LINKER_PATH "${CMAKE_SOURCE_DIR}/cubemx")

else()
    set(OTHER_INCLUDE_DIR
    )
endif()


setUnityTestProjectProperties(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR})

# Add optional definitions here ...
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
)
