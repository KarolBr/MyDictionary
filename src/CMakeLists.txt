SET(SRCS
	main.cpp
    Word.cpp
    Dictionary.cpp
    MyFile.cpp
    	)	


add_library(${CMAKE_PROJECT_NAME}_LIB ${SRCS})

target_include_directories(${CMAKE_PROJECT_NAME}_LIB PUBLIC 
    "../include"
    "${CMAKE_BINARY_DIR}/configured_files/include/"
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})