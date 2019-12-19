@echo off

if DEFINED DESTDIR (
  echo "Destdir.............%DESTDIR%"
  set DESTDIR_ARG="--root=%DESTDIR%"
)

cd "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control"

mkdir "C:/Users/MI/Desktop/Github/install\lib/site-packages"

set "PYTHONPATH=C:/Users/MI/Desktop/Github/install\lib/site-packages;C:/Users/MI/Desktop/Github/build\lib/site-packages"
set "CATKIN_BINARY_DIR=C:/Users/MI/Desktop/Github/build"
"C:/Opt/python27amd64/python.exe" ^
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control\setup.py" ^
    build --build-base "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control" ^
    install %DESTDIR_ARG%  ^
    --prefix="C:\Users\MI\Desktop\Github\install" ^
    --install-scripts="C:\Users\MI\Desktop\Github\install\bin"
