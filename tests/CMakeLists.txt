# Using TestManager Library
# Compile the TestManagere first into a lib.
set( TEST_API "tm")
add_library(${TEST_API} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/tm/tm.cpp)
target_include_directories( ${TEST_API} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tm )
set_target_properties( ${TEST_API} PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER tm/tm.h)
target_compile_features( ${TEST_API} PRIVATE cxx_std_17 )

# Add the always present main test...
add_executable( ${TEST_NAME} main.cpp ${CMAKE_SOURCE_DIR}/src/median.cpp )
target_include_directories( ${TEST_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tm
  PRIVATE ${CMAKE_SOURCE_DIR}/src)
#... and any other test source that have been created.
# target_sources( ${TEST_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_01.cpp" )
target_link_libraries( ${TEST_NAME} PRIVATE ${TEST_API} )
