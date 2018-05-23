project( KeychainLib  )

cmake_minimum_required( VERSION 3.0.2 )

set(CMAKE_CXX_FLAGS "-std=c++14")

SET(BOOST_COMPONENTS)
LIST(APPEND BOOST_COMPONENTS thread date_time system filesystem program_options signals serialization chrono unit_test_framework context locale iostreams)
SET( Boost_USE_STATIC_LIBS ON CACHE STRING "ON or OFF" )

SET(BOOST_ROOT $ENV{BOOST_ROOT})
set(Boost_USE_MULTITHREADED ON)
set(BOOST_ALL_DYN_LINK OFF)

FIND_PACKAGE(Boost 1.65 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
SET(BOOST_LIBRARIES_TEMP ${Boost_LIBRARIES})
FIND_PACKAGE(Boost 1.65 REQUIRED COMPONENTS coroutine)
LIST(APPEND BOOST_COMPONENTS coroutine)
SET(Boost_LIBRARIES ${BOOST_LIBRARIES_TEMP} ${Boost_LIBRARIES})


include_directories("./include/keychain_lib" "/opt/openssllib/include" "../3rd-party-components/include" "/usr/include/libcxxabi" ${Boost_INCLUDE_DIR})

file(GLOB KEYCHAIN_LIB_SOURCES "./src/*.cpp")
file(GLOB KEYCHAIN_LIB_INCLUDE "./include/keychain_lib/*.hpp")

add_library(keychain_common STATIC ${KEYCHAIN_LIB_SOURCES})