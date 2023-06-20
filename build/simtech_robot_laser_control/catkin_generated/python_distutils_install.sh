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

echo_and_run cd "/home/artc/GitHub/SIMTech_ws/src/simtech_robot_laser_control"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/artc/GitHub/SIMTech_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/artc/GitHub/SIMTech_ws/install/lib/python3/dist-packages:/home/artc/GitHub/SIMTech_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/artc/GitHub/SIMTech_ws/build" \
    "/usr/bin/python3" \
    "/home/artc/GitHub/SIMTech_ws/src/simtech_robot_laser_control/setup.py" \
     \
    build --build-base "/home/artc/GitHub/SIMTech_ws/build/simtech_robot_laser_control" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/artc/GitHub/SIMTech_ws/install" --install-scripts="/home/artc/GitHub/SIMTech_ws/install/bin"
