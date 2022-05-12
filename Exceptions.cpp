//
// Created by raulp on 4/28/2022.
//

#include "Exceptions.h"

RepositoryException::RepositoryException(string &exc_message) : message(exc_message) {}

const char* RepositoryException::what() const noexcept {
    return message.c_str();
}

UserException::UserException(string exc_message) : message(exc_message){}

const char* UserException::what() const noexcept {
    return message.c_str();
}

ValidationException::ValidationException(string &exc_message):message(exc_message) {}

const char* ValidationException::what() const noexcept {
    return message.c_str();
}