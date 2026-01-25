cmake_minimum_required(VERSION 3.13)
project(dnstool LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(dnstool game/dnstool.cpp)

if (WIN32)
  target_compile_definitions(dnstool PRIVATE _WIN32_WINNT=0x0601)
  target_link_libraries(dnstool PRIVATE Ws2_32 Iphlpapi)
endif()
