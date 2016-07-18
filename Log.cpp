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

namespace userstatusservice {

    Log::Log() {
        logger.assign(&(Poco::Logger::get("LogFile")));
        fileChannel.assign(new Poco::FileChannel());
        //    fileChannel->setProperty("rotation", "1 M");
        consoleChannel.assign(new Poco::ConsoleChannel());
        splitterChannel.assign(new Poco::SplitterChannel());
        splitterChannel->addChannel(fileChannel);
        splitterChannel->addChannel(consoleChannel);
        patternFormatter.assign(new Poco::PatternFormatter());
        patternFormatter->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
        patternFormatter->setProperty("times", "local");
        formattingChannel.assign(new Poco::FormattingChannel(patternFormatter, splitterChannel));
        logger->setChannel(formattingChannel);
    }

    void Log::write(std::string str) {
        std::lock_guard<std::mutex> guard(mutex_);
        Poco::Message msg;
        msg.setText(str);
        logger->log(msg);
    }

    void Log::setPath(std::string path) {
        std::lock_guard<std::mutex> guard(mutex_);
        if (!fileChannel.isNull()) { // Remove old file channel
            splitterChannel->removeChannel(fileChannel);
        }
        // Create and add new file channel
        fileChannel.assign(new Poco::FileChannel());
        fileChannel->setProperty("path", path);
        splitterChannel->addChannel(fileChannel);
    }
}