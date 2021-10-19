======
Sound Direction Detector
======

Quick start
===========

Setup project::

  $ west init -m https://github.com/bkoscielniak/sound_direction_detector.git
  $ west update

Install dependencies::

  $ pip3 install --user imgtool -r zephyr/scripts/requirements.txt

Build application::

  $ west build app

Flash application::

  $ west flash
