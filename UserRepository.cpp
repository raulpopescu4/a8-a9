//
// Created by raulp on 4/28/2022.
//

#include "UserRepository.h"

UserRepository::UserRepository() =default;

UserRepository::UserRepository(vector<Tutorial>& the_watchList) {
    this->watchList=the_watchList;
}

UserRepository::~UserRepository() = default;