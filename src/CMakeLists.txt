cmake_minimum_required (VERSION 3.0)

# set(PROJECT_NAME dbow3)
# project (${PROJECT_NAME})

############# cross compile options ##############
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++14")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX ${PROJECT_PATH}/build-s32v/output)
###################################################


# same as gcc -I
include_directories(
   include
)

# sources for create target
set (SRCS
  ${PUBLIC_H}
 BowVector.cpp
 Database.cpp
 DescManip.cpp
 FeatureVector.cpp
 QueryResults.cpp
 quicklz.c
 ScoringObject.cpp
 Vocabulary.cpp

 )

# compile
add_compile_options ($<$<BOOL:${HAVE_NO_UNNAMED_TYPE_TEMPLATE_ARGS}>:-Wno-unnamed-type-template-args>)
add_library (${PROJECT_NAME} SHARED ${SRCS} )




# define output
target_include_directories (${PROJECT_NAME} BEFORE PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
  "$<INSTALL_INTERFACE:include>"
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set_target_properties (${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_H}")

# make output
install (TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
