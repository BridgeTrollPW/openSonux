cmake_minimum_required(VERSION 3.0.0)
project(openSonux VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

##################################################
#
##################################################
include_directories(
"${PROJECT_SOURCE_DIR}/src"
"${PROJECT_SOURCE_DIR}/src/interceptor" 
"${PROJECT_SOURCE_DIR}/src/http" 
"${PROJECT_SOURCE_DIR}/src/router" 
"${PROJECT_SOURCE_DIR}/lib/easyloggingcpp" 
"${PROJECT_SOURCE_DIR}/lib"
"${PROJECT_SOURCE_DIR}/implementation"
)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE LIB RELATIVE ${CMAKE_SOURCE_DIR} "lib/*.cpp")
file(GLOB_RECURSE IMPL RELATIVE ${CMAKE_SOURCE_DIR} "imlpementation/*.cpp")

add_executable(openSonux main.cpp ${SOURCES} ${LIB} ${IMPL})

target_compile_options(openSonux PRIVATE -Werror)
target_compile_features(openSonux PRIVATE cxx_std_17)


##################################################
#
##################################################


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
