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

#include "AsyncTimer.h"

/**
 * Create an AsyncTimer.
 * 
 * @param length Number of milliseconds to wait before executing action.
 * @param actionEnd The action that will take place on timer expiration.
 * @param actionStart The action that will take on timer start (optional).
 */
AsyncTimer::AsyncTimer(unsigned long length, AsyncTimerActionFuncPtr actionEnd, AsyncTimerActionFuncPtr actionStart)
{
    this->config(length, actionEnd, actionStart);
}

/**
 * Initialize an AsyncTimer.
 * 
 * @param length Number of milliseconds to wait before executing action.
 * @param actionEnd The action that will take place on timer expiration.
 * @param actionStart The action that will take on timer start (optional).
 */
void AsyncTimer::config(unsigned long length, AsyncTimerActionFuncPtr actionEnd, AsyncTimerActionFuncPtr actionStart)
{
    this->length = length;
    this->actionEnd = *actionEnd;
    this->actionStart = *actionStart;
    isRunning = false;
}

/**
 * Start the timer. If it's already running, extend the expiration.
 */
void AsyncTimer::start()
{
    startTime = millis();
    if (actionStart)
    {
        (*actionStart)();
    }
    isRunning = true;
}

/**
 * Stop the timer without executing the action.
 */
void AsyncTimer::kill()
{
    isRunning = false;
}

/**
 * Execute action if timer has expired.
 * 
 * The timer is considered expired if it has been running for at least length 
 * milliseconds.
 * 
 * @return true iff the timer is no longer running (suggesting expiration).
 */
bool AsyncTimer::checkExpiration()
{
    if (isRunning && (millis() > startTime + length))
    {
        isRunning = false;
        (*actionEnd)();
    }
    return !isRunning;
}
