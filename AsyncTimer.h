/* 
 * File:   AsyncTimer.h
 * Author: mithat
 *
 * Created on October 25, 2015, 9:35 PM
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
 */
class AsyncTimer {
public:
    typedef void (*AsyncTimerActionFuncPtr)();
    AsyncTimer(unsigned long, AsyncTimerActionFuncPtr, AsyncTimerActionFuncPtr = NULL);
    virtual ~AsyncTimer();
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
