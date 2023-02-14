SET(SRCS
    main.cpp
    Word.cpp
    Dictionary.cpp
    MyFile.cpp
)	


add_library(${CMAKE_PROJECT_NAME}_LIB ${SRCS})

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME}_LIB)

target_include_directories(${CMAKE_PROJECT_NAME}_LIB PUBLIC 
    "../include"
    "${CMAKE_BINARY_DIR}/configured_files/include")


#add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
