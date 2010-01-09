CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(sharmanka)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
FIND_PACKAGE(wxWidgets COMPONENTS core base REQUIRED)
FIND_LIBRARY(MAD_LIBRARY mad)
FIND_PATH(MAD_INCLUDE_PATH mad.h)
FIND_LIBRARY(PORT_LIBRARY portaudiocpp)
FIND_PATH(PORT_INCLUDE_PATH portaudiocpp/PortAudioCpp.hxx)

##---------------------------------------------------
## Actual config file starts here
##---------------------------------------------------

# wxWidgets include directory
INCLUDE_DIRECTORIES(
  include
  ${wxWidgets_INCLUDE_DIRS}
  ${MAD_INCLUDE_PATH}
)

# add wxWidgets definitions
ADD_DEFINITIONS(${wxWidgets_DEFINITIONS})

# Everybody walks the dinosaur
FILE(GLOB SRCS src/*.cpp _shr_gui.cpp)
FILE(GLOB HDRS include/*.hpp _shr_gui.h)

# Here we define the executable minimal.exe or minimal on other systems
# the above paths and defines will be used in this build
ADD_EXECUTABLE(sharmanka
  ${SRCS}
  ${HDRS}
)

ADD_EXECUTABLE(dummy src/debug/Dummy.cpp src/MADWork.cpp src/PortAudio.cpp ${HDRS})

TARGET_LINK_LIBRARIES(sharmanka ${wxWidgets_LIBRARIES} ${MAD_LIBRARY} ${PORT_LIBRARY})
TARGET_LINK_LIBRARIES(dummy ${MAD_LIBRARY} ${PORT_LIBRARY})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

