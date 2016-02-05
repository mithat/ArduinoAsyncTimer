/**
 * @file
 * @author    Mithat Konar (mithat ~at~ mithatkonar.com)
 * @copyright Copyright (C) 2015 Mithat Konar
 * @section   LICENSE
 *
 * This file is part of AsyncTimer.
 *
 * AsyncTimer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AsyncTimer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this code. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ASYNCTIMER_H
#define	ASYNCTIMER_H

#include <Arduino.h>

/**
 * Pseudo-asynchronously execute a timer with optional start and mandatory
 * time-out actions.
 *
 * The time-out and start actions are specified as function pointers with no
 * parameters and no return value. After instantiation, execute the the start()
 * method when you want to start counting. The main loop() needs to be
 * configured to poll the checkExpiration() method every iteration.
 *
 * The timer is a one-shot. To make it a reapeating timer, call the timer's
 * start() method inside the actionEnd handler.
 *
 */
class AsyncTimer {
public:
    typedef void (*AsyncTimerActionFuncPtr)();
    AsyncTimer(unsigned long = 0xffff, AsyncTimerActionFuncPtr = NULL, AsyncTimerActionFuncPtr = NULL);
    void config(unsigned long, AsyncTimerActionFuncPtr, AsyncTimerActionFuncPtr = NULL);
    void start();
    void kill();
    boolean checkExpiration();

protected:
    unsigned long length;       // Number of milliseconds to wait before action.
    AsyncTimerActionFuncPtr actionEnd;    // The action to take on timer expiration.
    AsyncTimerActionFuncPtr actionStart;  // The action to take on timer start.
    bool isRunning;
    unsigned long startTime;    // The most recent time the timer was started.
};

#endif	/* ASYNCTIMER_H */
