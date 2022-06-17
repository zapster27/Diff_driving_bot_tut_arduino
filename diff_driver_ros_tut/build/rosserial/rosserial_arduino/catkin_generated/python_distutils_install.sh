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

echo_and_run cd "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/rosserial/rosserial_arduino"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/install/lib/python3/dist-packages:/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build" \
    "/usr/bin/python3" \
    "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/src/rosserial/rosserial_arduino/setup.py" \
     \
    build --build-base "/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/build/rosserial/rosserial_arduino" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/install" --install-scripts="/home/pi/Documents/Diff_driving_bot_tut_arduino/diff_driver_ros_tut/install/bin"
