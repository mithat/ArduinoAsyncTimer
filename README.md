AsyncTimer
=========

Copyright © 2015 [Mithat Konar](https://mithatkonar.com).

Licensed for use under the terms of the [GNU Lesser General Public License](http://www.gnu.org/licenses/lgpl-3.0.en.html).

AsyncTimer is maintained at https://github.com/mithat/ArduinoAsyncTimer.

Description
-----------

This library lets you create pseudo-asynchronous timers with optional start
and mandatory time-out actions. In other words, you can create a timer that
does something (or nothing) when you start it, then waits a predetermined
time before doing something else. While it's waiting, it doesn't lock up
your Arudino the way the `delay()` function does -- it just schedules the
time-out action to take place some time in the future.

The time-out and start actions are specified as function pointers with no
parameters and no return value. This is way less scary than it seems as you can
see from the examples.

In your code, the `loop()` function needs poll the timer object's `checkExpiration()` method. An AsyncTimer doesn't start automatically. To
start the timer, you need to execute the the `start()` method. If you want to 
cancel the timer without running the time-out action,  you can `kill()` it.
