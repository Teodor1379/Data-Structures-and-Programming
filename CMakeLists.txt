cmake_minimum_required(VERSION 3.24)



project("Data Structures and Programming" VERSION 1.0)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include(CMakePrintHelpers)



cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(CMAKE_PREFIX_PATH)



include(CTest)



if(BUILD_TESTING)

    message(STATUS "Make GoogleTest available...")

    if(EXISTS ${CMAKE_SOURCE_DIR}/lib/GoogleTest)
        add_subdirectory(${CMAKE_SOURCE_DIR}/lib/GoogleTest)
    else()
        include(FetchContent)

        FetchContent_Declare(
            GoogleTest
            GIT_REPOSITORY  https://github.com/google/googletest.git
            GIT_TAG         v1.15.2
            FIND_PACKAGE_ARGS
        )

        FetchContent_MakeAvailable(GoogleTest)
    endif()

endif()



include_directories("Source")
