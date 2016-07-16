/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Log.cpp
 * Author: ductn
 * 
 * Created on July 15, 2016, 9:50 AM
 */

#include "Log.h"

using namespace userstatusservice;

Log::Log() {
    logger = &(Poco::Logger::get("LogFile"));
    fileChannel = new Poco::FileChannel();
    fileChannel->setProperty("rotation", "1 M");
    consoleChannel = new Poco::ConsoleChannel();
    splitterChannel = new Poco::SplitterChannel();
//    splitterChannel->addChannel(fileChannel);
    splitterChannel->addChannel(consoleChannel);
    patternFormatter = new Poco::PatternFormatter();
    patternFormatter->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
    patternFormatter->setProperty("times", "local");
    formattingChannel = new Poco::FormattingChannel(patternFormatter, fileChannel);
    logger->setChannel(formattingChannel);
}

void Log::write(std::string str) {
    std::lock_guard<std::mutex> guard(mutex_);
    Poco::Message msg;
    msg.setText(str);
    logger->log(msg);
}

void Log::setPath(std::string path) {
    fileChannel->setProperty("path", path);
}