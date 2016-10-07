cmake_minimum_required(VERSION 3.6)
project(bigPower)

set(BOOST_ROOT d:\\boost)
include_directories("D:\\boost\\include\\boost-1_61")
link_directories("D:\\boost\\lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -mfpmath=sse -msse3")
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

set(SOURCE_FILES
        main.cpp
        bigNum.cpp bigNum.h bigPower.cpp bigPower.h
        #bigPowerTest.cpp
        )

add_executable(bigPower ${SOURCE_FILES})

target_link_libraries( bigPower
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#enable_testing()
#add_test(MyTest clion)