execute_process(COMMAND "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_arduino/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_arduino/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
