/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Checkpoint.cpp
 * Author: ductn
 * 
 * Created on July 15, 2016, 3:46 PM
 */

#include <Poco/Util/AbstractConfiguration.h>

#include "Checkpoint.h"

using namespace userstatusservice;

Checkpoint::Checkpoint() {
    checkPoint_ = "";
    data_ = NULL;
    log_ = NULL;
    config_ = NULL;
    //    DOMWriter_ = NULL;
}

Checkpoint::Checkpoint(boost::shared_ptr<Data> data, boost::shared_ptr<Log> log,
        Poco::AutoPtr<Poco::Util::XMLConfiguration> config) {
    data_ = data;
    log_ = log;
    config_ = config;
    //    DOMWriter_ = new Poco::XML::DOMWriter();
}

Checkpoint::Checkpoint(std::string checkPoint, boost::shared_ptr<Data> data,
        boost::shared_ptr<Log> log,
        Poco::AutoPtr<Poco::Util::XMLConfiguration> config) {
    checkPoint_ = checkPoint;
    data_ = data;
    log_ = log;
    config_ = config;
    //    DOMWriter_ = new Poco::XML::DOMWriter();
}

void Checkpoint::setCheckpoint(std::string newCheckPoint) {
    std::lock_guard<std::mutex> guard(mutex_);
    checkPoint_ = newCheckPoint;
    applyCheckpoint();
}

std::string Checkpoint::getCheckpoint() {
    std::lock_guard<std::mutex> guard(mutex_);
    return checkPoint_;
}

void Checkpoint::applyCheckpoint() {
    assert(!checkPoint_.empty());
    assert(data_ != NULL && log_ != NULL);
    data_->setPath(checkPoint_ + ".dat");
    log_->setPath(checkPoint_ + ".log");
}

void Checkpoint::setNewCheckpoint() {
    // Save stable dump and log to config file
    if (!checkPoint_.empty()) {
        config_->setString("checkPoint", checkPoint_);
        config_->save("config.xml");
    }
    // Get current time
    time_t now = time(0);
    tm* timeInfo = std::localtime(&now);
    std::string year = std::to_string(timeInfo->tm_year + 1900);
    std::string month = ((timeInfo->tm_mon < 9) ? "0" : "") +
            std::to_string(timeInfo->tm_mon + 1);
    std::string day = ((timeInfo->tm_mday < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_mday);
    std::string hour = ((timeInfo->tm_hour < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_hour);
    std::string min = ((timeInfo->tm_min < 10) ? "0" : "") +
            std::to_string(timeInfo->tm_min);
    std::string newCheckPoint = year + month + day + hour + min;
    // Set new check point
    setCheckpoint(newCheckPoint);
}