cmake_minimum_required(VERSION 3.0.0)
project(openSonux VERSION 0.1.0 LANGUAGES CXX)

#set(CMAKE_CXX_CLANG_TIDY
#    clang-tidy;
#    -header-filter=include/.;
#     -checks=*,-modernize-use-trailing-return-type,-llvmlibc-restrict-system-libc-headers,-llvmlibc-callee-namespace,-llvmlibc-implementation-in-namespace;)

include(CTest)
enable_testing()
#add_test(NAME openSonux COMMAND my_test)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

##################################################
#
##################################################
include_directories(
"${PROJECT_SOURCE_DIR}/source"
"${PROJECT_SOURCE_DIR}/include" 
"${PROJECT_SOURCE_DIR}/lib/easyloggingcpp" 
"${PROJECT_SOURCE_DIR}/lib"
"${PROJECT_SOURCE_DIR}/implementation"
)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE LIB RELATIVE ${CMAKE_SOURCE_DIR} "lib/easyloggingcpp/*.cpp")
file(GLOB_RECURSE IMPL RELATIVE ${CMAKE_SOURCE_DIR} "imlpementation/*.cpp")

add_executable(openSonux main.cpp ${SOURCES} ${LIB} ${IMPL})

target_compile_options(openSonux PRIVATE -Werror -fno-omit-frame-pointer -fsanitize=address)
target_compile_features(openSonux PRIVATE cxx_std_17)
target_link_libraries(openSonux Threads::Threads -lasan -lubsan)
##################################################
#
##################################################


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

