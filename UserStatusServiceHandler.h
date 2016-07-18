/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserStatusServiceHandler.h
 * Author: ductn
 *
 * Created on July 18, 2016, 2:56 PM
 */

#ifndef USERSTATUSSERVICEHANDLER_H
#define USERSTATUSSERVICEHANDLER_H

#include "UserStatusService.h"
#include "Data.h"
#include "Log.h"
#include "Checkpoint.h"
#include "Timer.h"
#include <Poco/AutoPtr.h>
#include <Poco/Util/XMLConfiguration.h>
#include <boost/algorithm/string.hpp>
#include <iostream>

class UserStatusServiceHandler : virtual public userstatusservice::UserStatusServiceIf {
public:
    UserStatusServiceHandler();
    void loading();
    bool getUserStatus(const int64_t ID);
    void setUserStatus(const int64_t ID, const bool status);
private:
    Poco::AutoPtr<Poco::Util::XMLConfiguration> config;
    boost::shared_ptr<userstatusservice::Data> data;
    boost::shared_ptr<userstatusservice::Checkpoint> checkPoint;
    boost::shared_ptr<userstatusservice::Log> log;
    boost::shared_ptr<userstatusservice::Timer> timer;
};

#endif /* USERSTATUSSERVICEHANDLER_H */

