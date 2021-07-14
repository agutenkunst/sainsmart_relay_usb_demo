cmake_minimum_required(VERSION 3.0.2)
project(sainsmart_relay_usb_demo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
   CATKIN_DEPENDS roscpp std_msgs
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)

find_package(rostest REQUIRED)

add_rostest_gtest(relay_test
  test/relay_test.test
  test/relay_test.cpp
)

target_link_libraries(relay_test
  ${catkin_LIBRARIES}
)

endif()