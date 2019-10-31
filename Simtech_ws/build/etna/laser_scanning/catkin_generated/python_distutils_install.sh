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

echo_and_run cd "/home/david/Simtech_ws/src/etna/laser_scanning"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/david/Simtech_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/david/Simtech_ws/install/lib/python2.7/dist-packages:/home/david/Simtech_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/david/Simtech_ws/build" \
    "/usr/bin/python" \
    "/home/david/Simtech_ws/src/etna/laser_scanning/setup.py" \
    build --build-base "/home/david/Simtech_ws/build/etna/laser_scanning" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/david/Simtech_ws/install" --install-scripts="/home/david/Simtech_ws/install/bin"
