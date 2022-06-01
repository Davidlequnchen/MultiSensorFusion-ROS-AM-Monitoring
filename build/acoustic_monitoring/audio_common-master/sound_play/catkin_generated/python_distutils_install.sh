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

echo_and_run cd "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/audio_common-master/sound_play"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/lequn/Documents/GitHub/SIMTech_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/lequn/Documents/GitHub/SIMTech_ws/install/lib/python3/dist-packages:/home/lequn/Documents/GitHub/SIMTech_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/lequn/Documents/GitHub/SIMTech_ws/build" \
    "/usr/bin/python3" \
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/audio_common-master/sound_play/setup.py" \
    egg_info --egg-base /home/lequn/Documents/GitHub/SIMTech_ws/build/acoustic_monitoring/audio_common-master/sound_play \
    build --build-base "/home/lequn/Documents/GitHub/SIMTech_ws/build/acoustic_monitoring/audio_common-master/sound_play" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/lequn/Documents/GitHub/SIMTech_ws/install" --install-scripts="/home/lequn/Documents/GitHub/SIMTech_ws/install/bin"
