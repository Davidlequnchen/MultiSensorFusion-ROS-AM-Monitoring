^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rosbag_pandas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.4 (2020-08-25)
------------------
* chore: Noetic compatibility
* chore: use dict.items() instead of iteritems()
  iteritems was [removed in python3](https://wiki.python.org/moin/Python3.0#Built-In_Changes).
  items() is working both on Python2 and Python3
* docs: removed extra round bracket
* Update .travis.yml
* Bag plot example in readme
* Bag plot image for doc
* Contributors: Rein Appeldoorn, Valerio Magnago

0.5.3 (2019-03-21)
------------------
* flatdict dep in package
* Contributors: Rein Appeldoorn

0.5.2 (2019-02-27)
------------------
* Update .travis.yml
* Update README.md
* only module import
* required arguments
* Contributors: Rein Appeldoorn

0.5.1 (2018-11-02)
------------------
* Refactor rosbag_pandas
  - Support dynamic arrays
  - Key pattern specification conform rostopic msgevalgen
  - Renamed scripts (and fixed scripts)
  - Added new unit test
  - Cleanup package
  - pep8 compliance
  - Updated documentation README
* Fork from `https://github.com/aktaylor08/RosbagPandas`, see `https://github.com/aktaylor08/RosbagPandas/issues/11`
* Contributors: Adam Taylor, Felix, Low Kian Seong, Ramon Wijnands, Rein Appeldoorn, itsb, turtlebot
