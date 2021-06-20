cmake_minimum_required(VERSION 3.18)
project(TankBotFight)
set(CMAKE_CXX_STANDARD 20)

include(CTest)

set(SFML_VERSION "2.5.1")

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(tank_bot_fight 
    src/main.cpp 
    src/Tank.cpp 
    src/Obstacle.cpp)

if(MSVC)
    target_compile_options(tank_bot_fight PRIVATE /W3 /WX /O2)
else()
    target_compile_options(tank_bot_fight PRIVATE -Wall -pedantic -Werror -Wextra -O3)
endif()

target_include_directories(tank_bot_fight PRIVATE src)

target_link_libraries(tank_bot_fight sfml-graphics)

find_package(Protobuf REQUIRED
    PATHS ${PROTOBUF_SEARCH_PATH}
)

if (NOT ${Protobuf_FOUND})
    message( FATAL_ERROR "Could not find Protobuf!" )
endif()    

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS Foo.proto)

add_subdirectory(test)
add_subdirectory(proto)
