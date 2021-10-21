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

echo_and_run cd "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/audio_common/sound_play"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/chenlequn/SIMTech_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/chenlequn/SIMTech_ws/install/lib/python2.7/dist-packages:/home/chenlequn/SIMTech_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/chenlequn/SIMTech_ws/build" \
    "/usr/bin/python2" \
    "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/audio_common/sound_play/setup.py" \
    egg_info --egg-base /home/chenlequn/SIMTech_ws/build/acoustic_monitoring/audio_common/sound_play \
    build --build-base "/home/chenlequn/SIMTech_ws/build/acoustic_monitoring/audio_common/sound_play" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/chenlequn/SIMTech_ws/install" --install-scripts="/home/chenlequn/SIMTech_ws/install/bin"
