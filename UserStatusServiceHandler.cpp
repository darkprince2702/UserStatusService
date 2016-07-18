/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserStatusServiceHandler.cpp
 * Author: ductn
 * 
 * Created on July 18, 2016, 2:56 PM
 */

#include "UserStatusServiceHandler.h"

using namespace userstatusservice;

UserStatusServiceHandler::UserStatusServiceHandler() :
config(new Poco::Util::XMLConfiguration("config.xml")) {
    if (config->has("checkPoint")) { // Checkpoint found
        data = boost::make_shared<Data>();
        log = boost::make_shared<Log>();
        std::string cpFrFile = config->getString("checkPoint");
        checkPoint = boost::make_shared<Checkpoint>(cpFrFile, data, log, config);
        loading();
        // Set checkpoint to now
        checkPoint->setNewCheckpoint();
        std::cout << "checkPoint found, load data from file" << std::endl;
    } else { // No checkpoint, must init
        int blockNum = config->getInt("blockNum");
        int blockSize = config->getInt("blockSize");
        data = boost::make_shared<Data>(blockNum, blockSize);
        data->init();
        log = boost::make_shared<Log>();
        checkPoint = boost::make_shared<Checkpoint>(data, log, config);
        // Set checkpoint to now
        checkPoint->setNewCheckpoint();
        std::cout << "checkPoint not found, initialize data" << std::endl;
    }
    // Create timer and run it
    int interval = config->getInt("logInterval", 120);
    timer = boost::make_shared<Timer>(interval, data, log, checkPoint);
    timer->start();
}

void UserStatusServiceHandler::loading() {
    // Load data from dump file
    data->load();
    // Load operations from log
    std::ifstream file;
    file.open(checkPoint->getCheckpoint() + ".log",
            std::ios::in | std::ios::binary);
    if (file.is_open()) {
        std::string line;
        // Get line by line in opened file
        while (std::getline(file, line)) {
            std::vector<std::string> tokens;
            // Split gotten line into tokens
            boost::split(tokens, line, boost::is_any_of(" "));
            if (tokens[3] == "setBit") { // It's set task
                data->setBit(std::atol(tokens[4].c_str()));
            } else if (tokens[3] == "clearBit") { // It's remove task
                data->clearBit(std::atol(tokens[4].c_str()));
            }
        }
        file.close();
    }
}

bool UserStatusServiceHandler::getUserStatus(const int64_t ID) {
    log->write("getBit " + std::to_string(ID));
    int8_t result = data->getBit(ID);
    assert(result == 0 || result == 1);
    return (result != 0) ? true : false;
}

void UserStatusServiceHandler::setUserStatus(const int64_t ID, const bool status) {
    if (status) {
        log->write("setBit " + std::to_string(ID));
        data->setBit(ID);
    } else {
        log->write("clearBit " + std::to_string(ID));
        data->clearBit(ID);
    }
}
