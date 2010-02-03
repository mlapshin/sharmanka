CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(sharmanka)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
FIND_PACKAGE(wxWidgets COMPONENTS core base xrc net REQUIRED)
FIND_LIBRARY(MAD_LIBRARY mad)
FIND_PATH(MAD_INCLUDE_PATH mad.h)
FIND_LIBRARY(PORT_LIBRARY portaudiocpp)
FIND_PATH(PORT_INCLUDE_PATH portaudiocpp/PortAudioCpp.hxx)

##---------------------------------------------------
## Actual config file starts here
##---------------------------------------------------

# wxWidgets include directory
INCLUDE_DIRECTORIES(
  .
  include
  ${wxWidgets_INCLUDE_DIRS}
  ${MAD_INCLUDE_PATH}
)

# add wxWidgets definitions
ADD_DEFINITIONS(${wxWidgets_DEFINITIONS})

SET(CMAKE_BUILD_TYPE debug)

# Custom pre-build step to generate GUI sources from wxFormBuilder project
ADD_CUSTOM_COMMAND(
  OUTPUT ${CMAKE_SOURCE_DIR}/_shr_gui.h ${CMAKE_SOURCE_DIR}/_shr_gui.cpp
  COMMAND wxformbuilder -g ${CMAKE_SOURCE_DIR}/sharmanka.fbp
  MAIN_DEPENDENCY ${CMAKE_SOURCE_DIR}/sharmanka.fbp
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Generating code from wxFormBuilder project"
)

# Custom pre-build step to compile CPP resource file
ADD_CUSTOM_COMMAND(
  OUTPUT ${CMAKE_SOURCE_DIR}/_resources.cpp
  COMMAND ${wxWidgets_wxrc_EXECUTABLE} -c -o ${CMAKE_SOURCE_DIR}/_resources.cpp ${CMAKE_SOURCE_DIR}/sharmanka.xrc
  MAIN_DEPENDENCY ${CMAKE_SOURCE_DIR}/sharmanka.xrc
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Compiling resource files"
)

ADD_CUSTOM_TARGET(
  lampampam
  DEPENDS ${CMAKE_SOURCE_DIR}/_resources.cpp ${CMAKE_SOURCE_DIR}/_shr_gui.cpp ${CMAKE_SOURCE_DIR}/_shr_gui.h
)

# Common everybody
FILE(GLOB SRCS src/*.cpp)
FILE(GLOB HDRS include/*.hpp)

# don't forget our generated stuff...
LIST(APPEND SRCS ${CMAKE_SOURCE_DIR}/_shr_gui.cpp ${CMAKE_SOURCE_DIR}/_resources.cpp)
LIST(APPEND HDRS ${CMAKE_SOURCE_DIR}/_shr_gui.h)

ADD_EXECUTABLE(
  sharmanka
  ${SRCS}
  ${HDRS}
)

ADD_EXECUTABLE(dummy src/debug/Dummy.cpp src/MADWork.cpp src/PortAudio.cpp src/PerfTimer.cpp ${HDRS})

TARGET_LINK_LIBRARIES(sharmanka ${wxWidgets_LIBRARIES} ${MAD_LIBRARY} ${PORT_LIBRARY})
TARGET_LINK_LIBRARIES(dummy ${MAD_LIBRARY} ${PORT_LIBRARY})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

