CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(sharmanka)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
FIND_PACKAGE(wxWidgets COMPONENTS core base REQUIRED)

##---------------------------------------------------
## Actual config file starts here
##---------------------------------------------------

# wxWidgets include directory
INCLUDE_DIRECTORIES(
  include
  ${wxWidgets_INCLUDE_DIRS}
)

# add wxWidgets definitions
ADD_DEFINITIONS(${wxWidgets_DEFINITIONS})

# Everybody walks the dinosaur
FILE(GLOB SRCS src/*.cpp)
FILE(GLOB HDRS include/*.hpp)

# Here we define the executable minimal.exe or minimal on other systems
# the above paths and defines will be used in this build
ADD_EXECUTABLE(sharmanka
  ${SRCS}
  ${HDRS}
)

TARGET_LINK_LIBRARIES(sharmanka ${wxWidgets_LIBRARIES})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)