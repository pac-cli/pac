cmake_minimum_required(VERSION 3.12)

project(pac)
file(GLOB SRC CONFIGURE_DEPENDS "./src/**/*.h" "./src/dependencies/*.hpp" "./src/**/*.cpp")
add_executable(pac ${SRC})
