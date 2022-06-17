# Install script for directory: /home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE PROGRAM FILES "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE PROGRAM FILES "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/setup.bash;/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE FILE FILES
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/setup.bash"
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/setup.sh;/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE FILE FILES
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/setup.sh"
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/setup.zsh;/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE FILE FILES
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/setup.zsh"
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" TYPE FILE FILES "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/gtest/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_arduino/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_chibios/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_mbed/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_msgs/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_python/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_tivac/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_vex_cortex/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_vex_v5/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_xbee/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_client/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/diff_driver/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/odom_publisher/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/tick_publisher/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_server/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rplidar_ros/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_test/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_windows/cmake_install.cmake")
  include("/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/diff_drive_bot_with_lidar/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
