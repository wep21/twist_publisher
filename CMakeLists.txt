cmake_minimum_required(VERSION 3.5)
project(twist_publisher)

### Compile options
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-parameter -Wall -Wextra -Wpedantic)
endif()

### Dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

### Target executable
ament_auto_add_library(twist_publisher SHARED
  src/twist_publisher.cpp
)

rclcpp_components_register_node(twist_publisher
  PLUGIN "TwistPublisher"
  EXECUTABLE twist_publisher_node
)

ament_auto_package(INSTALL_TO_SHARE
  launch
)

