/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: ductn
 *
 * Created on July 12, 2016, 3:08 PM
 */

#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdint.h>
#include <mutex>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/array.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace userstatusservice {

    class Data {
    public:
        Data();
        Data(int blockNum, int blockSize);
        void init();
        int8_t getBit(int64_t pos);
        void setBit(int64_t pos);
        void clearBit(int64_t pos);
        void save();
        void load();
        void setPath(std::string path);
        ~Data();
    private:
        int8_t** data_;
        int32_t blockNum_;
        int32_t blockSize_;
        int8_t blockBit_;
        int64_t modNum_;
        std::string path_;
        std::mutex mutex_;
        friend class boost::serialization::access;
        template <typename Archive>
        void serialize(Archive &ar, const unsigned int version);
    };

}
#endif /* DATA_H */

