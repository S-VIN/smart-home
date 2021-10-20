project(smartHome)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)
set(SRC_LIST
        main.cpp
        orm/Connections.h
        orm/statedb.h
        Basis.h)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_subdirectory(include/stringOperations)
#add_subdirectory(tests)

target_link_libraries(smartHome  ${PQXX_LIB} ${PQ_LIB})
#target_link_libraries(${PROJECT_NAME} stringsOperations)