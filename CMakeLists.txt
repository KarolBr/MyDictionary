cmake_minimum_required(VERSION 3.12)
project(MyDictionary VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

SET(SRCS
	src/main.cpp
    src/Word.cpp
    src/Dictionary.cpp
    	)	

SET(UT_SRCS
	uts/project-test.cpp
	)

enable_testing()
##

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

include_directories(
    include
)


add_library(${CMAKE_PROJECT_NAME}_LIB ${SRCS})
target_include_directories(${CMAKE_PROJECT_NAME}_LIB PUBLIC include)

add_executable(${CMAKE_PROJECT_NAME}_test ${UT_SRCS}) 
target_link_libraries(${CMAKE_PROJECT_NAME}_test gtest gtest_main ${CMAKE_PROJECT_NAME}_LIB)
##



include(GoogleTest)
#gtest_discover_tests(hello_test)
