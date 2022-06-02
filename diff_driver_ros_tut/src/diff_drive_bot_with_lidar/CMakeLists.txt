cmake_minimum_required(VERSION 2.8.3)

project(diff_drive_bot_with_lidar)

find_package(catkin REQUIRED)

catkin_package()

find_package(roslaunch)

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
add_library(lidar_plugin plugins/lidar_plugin.cc)