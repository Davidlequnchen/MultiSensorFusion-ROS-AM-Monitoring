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
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/Monitoring/Laser_calibration/calib_ros_test"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/yaoxl/Documents/GitHub/SIMTech_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/yaoxl/Documents/GitHub/SIMTech_ws/install/lib/python2.7/dist-packages:/home/yaoxl/Documents/GitHub/SIMTech_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/yaoxl/Documents/GitHub/SIMTech_ws/build" \
    "/usr/bin/python2" \
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/Monitoring/Laser_calibration/calib_ros_test/setup.py" \
    build --build-base "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/Monitoring/Laser_calibration/calib_ros_test" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/yaoxl/Documents/GitHub/SIMTech_ws/install" --install-scripts="/home/yaoxl/Documents/GitHub/SIMTech_ws/install/bin"
