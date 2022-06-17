#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/src/rosserial/rosserial_arduino"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/lib/python3/dist-packages:/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build" \
    "/usr/bin/python3" \
    "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/src/rosserial/rosserial_arduino/setup.py" \
     \
    build --build-base "/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/build/rosserial/rosserial_arduino" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install" --install-scripts="/home/ubuntu/Documents/DiffDriveRobotCode_mk1/diff_driver_ros_tut/install/bin"
