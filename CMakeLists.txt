project(smartHome)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)
set(SRC_LIST
        main.cpp
        Orm/Connections.h
        Orm/statedb.h
        Basis.h Connectors/IConnector.h Connectors/Usual.h)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_subdirectory(include/stringOperations)
#add_subdirectory(tests)

target_link_libraries(smartHome  ${PQXX_LIB} ${PQ_LIB} ${Boost_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} stringsOperations)