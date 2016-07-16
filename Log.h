/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Log.h
 * Author: ductn
 *
 * Created on July 15, 2016, 9:50 AM
 */

#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <assert.h>
#include <mutex>
#include <Poco/Logger.h>
#include <Poco/FileChannel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/SplitterChannel.h>
#include <Poco/Message.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>

namespace userstatusservice {

    class Log {
    public:
        Log();
        void write(std::string str);
        void setPath(std::string path);
    private:
        Poco::Logger* logger;
        Poco::FileChannel* fileChannel;
        Poco::ConsoleChannel* consoleChannel;
        Poco::SplitterChannel* splitterChannel;
        Poco::PatternFormatter* patternFormatter;
        Poco::FormattingChannel* formattingChannel;
        std::mutex mutex_;
    };
    
};

#endif /* LOG_H */

