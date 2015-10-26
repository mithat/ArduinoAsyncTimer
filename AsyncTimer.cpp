/* 
 * File:   AsyncTimer.cpp
 * Author: mithat
 * 
 * Created on October 25, 2015, 9:35 PM
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
    this->length = length;
    this->actionEnd = *actionEnd;
    this->actionStart = *actionStart;
    isRunning = false;
}

AsyncTimer::~AsyncTimer()
{
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
