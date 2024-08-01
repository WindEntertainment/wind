project(wind-event-manager)

set(HEADERS
    ./include/wind-event-manager/convertor.hpp
    ./include/wind-event-manager/emitter.hpp
)

set(SOURCES
    ./src/convertor.cpp
    ./src/emitter.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${HEADERS} ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ./include/)

find_package(Boost REQUIRED COMPONENTS system filesystem)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::system Boost::filesystem)

target_link_libraries(${PROJECT_NAME} PRIVATE wind-ultralight)
