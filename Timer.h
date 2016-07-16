/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.h
 * Author: ductn
 *
 * Created on July 16, 2016, 9:09 AM
 */

#ifndef TIMER_H
#define TIMER_H

#include "Data.h"
#include "Log.h"
#include "Checkpoint.h"
#include <boost/thread.hpp>
#include <event.h>
#include <assert.h>

namespace userstatusservice {

    class Timer {
    public:
        Timer(boost::shared_ptr<Data> data, boost::shared_ptr<Log> log,
                boost::shared_ptr<Checkpoint> checkpoint);
        Timer(int interval, boost::shared_ptr<Data> data, boost::shared_ptr<Log> log,
                boost::shared_ptr<Checkpoint> checkpoint);
        ~Timer();
        void runLoop();
        void stopLoop();
        void start();
        void registerEvents();
        static void doTaskCallback(evutil_socket_t fd, short what, void *arg);
    private:
        boost::shared_ptr<Data> data_;
        boost::shared_ptr<Log> log_;
        boost::shared_ptr<Checkpoint> checkpoint_;
        event_base* eventBase_;
        event* event_;
        int interval_;
        boost::thread* thread_;
    };
}
#endif /* TIMER_H */

