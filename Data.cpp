/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.cpp
 * Author: ductn
 * 
 * Created on July 12, 2016, 3:08 PM
 */

#include "Data.h"

using namespace userstatusservice;

Data::Data() {
    path_ = "";
}

Data::Data(int blockNum, int blockSize) {
    path_ = "";
    blockNum_ = blockNum;
    blockSize_ = blockSize;
    blockBit_ = 0;
    // blockBit_ = log^2{blockSize_};
    int32_t blSz = blockSize;
    while (blSz != 1) {
        blockBit_++;
        blSz = blSz >> 1;
    }
}

Data::~Data() {
    for (int i = 0; i < blockNum_; i++) {
        free(data_[i]);
    }
}

void Data::init() {
    assert(blockNum_ != 0 && blockSize_ != 0);
    // calculate mod number
    modNum_ = blockSize_ - 1;
    data_ = new int8_t*[blockNum_];
    for (int i = 0; i < blockNum_; i++) {
        int32_t arraySize = blockSize_ / 8 + 1;
        data_[i] = (int8_t*) malloc(arraySize * sizeof (int8_t));
        memset(data_[i], 0, arraySize);
    }
}

int8_t Data::getBit(int64_t pos) {
    assert(pos >= 0 && pos <= (blockSize_ * blockNum_));
    std::lock_guard<std::mutex> guard(mutex_);
    // get block number and position in block
    int64_t nBlock = pos >> blockBit_;
    int64_t nPosInBlock = pos & modNum_;
    int64_t nChar = nPosInBlock >> 3;
    int8_t nPos = nPosInBlock & 7;
    // get result
    int8_t result = (data_[nBlock][nChar] >> nPos) & 1;
    return result;
}

void Data::setBit(int64_t pos) {
    assert(pos >= 0 && pos <= (blockSize_ * blockNum_));
    std::lock_guard<std::mutex> guard(mutex_);
    // get block number and position in block
    int64_t nBlock = pos >> blockBit_;
    int64_t nPosInBlock = pos & modNum_;
    int64_t nChar = nPosInBlock >> 3;
    int8_t nPos = nPosInBlock & 7;
    // set the bit
    data_[nBlock][nChar] |= (1 << nPos);
    return;
}

void Data::clearBit(int64_t pos) {
    assert(pos >= 0 && pos <= blockSize_ * blockNum_);
    std::lock_guard<std::mutex> guard(mutex_);
    // get block number and position in block
    int64_t nBlock = pos >> blockBit_;
    int64_t nPosInBlock = pos & modNum_;
    int64_t nChar = nPosInBlock >> 3;
    int8_t nPos = nPosInBlock & 7;
    // set the bit
    data_[nBlock][nChar] &= ~(1 << nPos);
    return;
}

template<typename Archive>
void Data::serialize(Archive& ar, const unsigned int version) {
    ar & blockNum_;
    ar & blockSize_;
    ar & blockBit_;
    ar & modNum_;
    if (Archive::is_loading::value) {
        data_ = new int8_t*[blockNum_];
    }

    for (int i = 0; i < blockNum_; i++) {
        int32_t arraySize = blockSize_ / 8 + 1;
        if (Archive::is_loading::value) {
            data_[i] = new int8_t[arraySize];
        }
        ar & boost::serialization::make_array<int8_t>(data_[i], arraySize);
    }
}

void Data::save() {
    std::lock_guard<std::mutex> guard(mutex_);
    Data* obj = this;
    std::ofstream outStream(path_, std::ios::out | std::ios::binary | std::ios::trunc);
    boost::archive::binary_oarchive oar(outStream);
    oar << (*obj);
}

void Data::load() {
    std::lock_guard<std::mutex> guard(mutex_);
    Data* obj = this;
    std::ifstream inStream(path_, std::ios::in | std::ios::binary);
    boost::archive::binary_iarchive iar(inStream);
    iar >> *obj;
}

void Data::setPath(std::string path) {
    std::lock_guard<std::mutex> guard(mutex_);
    path_ = path;
}