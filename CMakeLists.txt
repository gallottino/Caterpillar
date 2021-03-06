cmake_minimum_required(VERSION 3.14)
project(Caterpillar)


set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES src/main.cpp src/SnakeBlock.cpp)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
set(SFML_INCLUDE_DIR "C:/SFML-2.5.1/include/")
link_directories("C:/SFML-2.5.1/lib/")


set(YOUR_DIRECTORY "./")
add_executable(Caterpillar ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(Caterpillar PRIVATE ${YOUR_DIRECTORY}/include/)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Caterpillar sfml-graphics-d sfml-window-d sfml-system-d)
endif()