/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.cpp
 * Author: ductn
 * 
 * Created on July 16, 2016, 9:09 AM
 */

#include "Timer.h"

using namespace userstatusservice;

Timer::Timer(boost::shared_ptr<Data> data, boost::shared_ptr<Log> log,
        boost::shared_ptr<Checkpoint> checkpoint) {
    interval_ = 60;
    data_ = data;
    log_ = log;
    checkpoint_ = checkpoint;
    eventBase_ = NULL;
    event_ = NULL;
    thread_ = NULL;
}

Timer::Timer(int interval, boost::shared_ptr<Data> data, boost::shared_ptr<Log> log, boost::shared_ptr<Checkpoint> checkpoint) {
    interval_ = interval;
    data_ = data;
    log_ = log;
    checkpoint_ = checkpoint;
    eventBase_ = NULL;
    event_ = NULL;
    thread_ = NULL;
}

void Timer::registerEvents() {
    if (eventBase_ == NULL) {
        eventBase_ = event_base_new();
    }

    event_ = event_new(eventBase_, -1, EV_PERSIST, Timer::doTaskCallback, this);
    timeval* interval = new timeval();
    interval->tv_sec = interval_;
    interval->tv_usec = 0;
    event_add(event_, interval);
}

void Timer::doTaskCallback(int fd, short what, void* arg) {
    Timer* timer = (Timer*) arg;
    assert(timer != NULL);
    // Dump data to file before get new checkpoint
    timer->data_->save();
    // get new checkpoint
    timer->checkpoint_->setNewCheckpoint();
}

void Timer::runLoop() {
    registerEvents();
    event_base_loop(eventBase_, 0);
}

void Timer::stopLoop() {
    event_base_loopbreak(eventBase_);
}

void Timer::start() {
    thread_ = new boost::thread(&Timer::runLoop, this);
    thread_->detach();
}

Timer::~Timer() {
    stopLoop();
    event_free(event_);
    event_base_free(eventBase_);
    delete thread_;
}
