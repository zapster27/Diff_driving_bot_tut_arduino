# Install script for directory: /home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build/diffdrivebot/catkin_generated/installspace/diffdrivebot.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot/cmake" TYPE FILE FILES
    "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build/diffdrivebot/catkin_generated/installspace/diffdrivebotConfig.cmake"
    "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build/diffdrivebot/catkin_generated/installspace/diffdrivebotConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot" TYPE FILE FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot/config" TYPE DIRECTORY FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot/config/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot/launch" TYPE DIRECTORY FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot/launch/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot/meshes" TYPE DIRECTORY FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot/meshes/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/diffdrivebot/urdf" TYPE DIRECTORY FILES "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/diffdrivebot/urdf/")
endif()

