cmake_minimum_required(VERSION 3.0)

project(wsjcpp-print-tree C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-print-tree_SOURCE_DIR})

# Sources

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_print_tree.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_print_tree.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (wsjcpp-print-tree ${WSJCPP_SOURCES})

target_link_libraries(wsjcpp-print-tree ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        wsjcpp-print-tree
    RUNTIME DESTINATION
        /usr/bin
)
