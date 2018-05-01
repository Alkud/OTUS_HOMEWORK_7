#CmakeList.txt for OTUS Homework #7

#Check CMake version
cmake_minimum_required(VERSION 3.2)

#Set project name, set PROJECT_VERSION_MINOR value equal to TRAVIS_BUILD NUMBER
if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
  set (VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
else ()
  set (VERSION_PATCH 1)
endif()

project(bulk VERSION 0.0.${VERSION_PATCH})

set (BOOST_MIN_VERSION "1.54.0")

#Find Boost UTF component, get BOOST_LIBRARIES and BOOST_INCLUDE_DIR values
find_package(Boost COMPONENTS unit_test_framework REQUIRED)


#Set library target
add_library(command_processor ./library/command_processor.cpp)
add_library(input_processor ./library/input_processor.cpp)
add_library(input_reader ./library/input_reader.cpp)
add_library(logger ./library/logger.cpp)
add_library(publisher ./library/publisher.cpp)

add_library(broadcasters INTERFACE)
target_sources(broadcasters INTERFACE ${PROJECT_SOURCE_DIR}/library/broadcasters.h)
target_include_directories(broadcasters INTERFACE ${PROJECT_SOURCE_DIR}/library)
add_library(listeners INTERFACE)
target_sources(listeners INTERFACE ${PROJECT_SOURCE_DIR}/library/listeners.h)
target_include_directories(listeners INTERFACE ${PROJECT_SOURCE_DIR}/library)
add_library(smart_buffer INTERFACE)
target_sources(smart_buffer INTERFACE ${PROJECT_SOURCE_DIR}/library/smart_buffer.h)
target_include_directories(smart_buffer INTERFACE ${PROJECT_SOURCE_DIR}/library)


#Set executable target
add_executable(bulk bulk.cpp)

#Set test target_link_libraries
add_executable(otus_hw_7_test otus_hw_7_test.cpp)

#Enable tests
enable_testing()
add_test(
NAME test_hw_7
COMMAND otus_hw_7_test)

#Set properties and compile options for executable target
set_target_properties(bulk
  PROPERTIES CXX_STANDARD 14
             CXX_STANDARD_REQUIRED ON
             COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#Set properties for test target
set_target_properties(otus_hw_7_test PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

#Link
target_link_libraries(bulk command_processor)
target_link_libraries(command_processor
                      input_processor input_reader logger publisher)
target_link_libraries(input_reader
                      broadcasters
                      smart_buffer)
target_link_libraries(input_processor
                      listeners
                      smart_buffer)
target_link_libraries(logger
                      broadcasters listeners
                      smart_buffer)
target_link_libraries(publisher
                      broadcasters listeners
                      smart_buffer)
target_link_libraries(smart_buffer INTERFACE
                      broadcasters listeners)

target_link_libraries(otus_hw_7_test
                      ${Boost_LIBRARIES}
                      command_processor)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexandr_kudinov@mail.ru)

include(CPack)
