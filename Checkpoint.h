/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Checkpoint.h
 * Author: ductn
 *
 * Created on July 15, 2016, 3:46 PM
 */

#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <mutex>
#include <ctime>
#include <Poco/Util/XMLConfiguration.h>
#include <Poco/XML/XMLWriter.h>
#include "Data.h"
#include "Log.h"
namespace userstatusservice {

    class Checkpoint {
    public:
        Checkpoint();
        Checkpoint(boost::shared_ptr<Data> data, boost::shared_ptr<Log> log,
                Poco::AutoPtr<Poco::Util::XMLConfiguration> config);
        Checkpoint(std::string checkPoint, boost::shared_ptr<Data> data,
                boost::shared_ptr<Log> log,
                Poco::AutoPtr<Poco::Util::XMLConfiguration> config);
        void setCheckpoint(std::string newCheckPoint);
        std::string getCheckpoint();
        void applyCheckpoint();
        void setNewCheckpoint();
    private:
        std::string checkPoint_;
        boost::shared_ptr<Data> data_;
        boost::shared_ptr<Log> log_;
        Poco::AutoPtr<Poco::Util::XMLConfiguration> config_;
        Poco::XML::DOMWriter DOMWriter_;
        std::mutex mutex_;
    };
}
#endif /* CHECKPOINT_H */