//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_EXCEPTIONS_H
#define A5_A6_EXCEPTIONS_H
#include <string>
using namespace std;

class RepositoryException: public exception{
private:
    string message;
public:
    explicit RepositoryException(string& exc_message);

    const char *what()const noexcept override;
};

class UserException: public exception{
private:
    string message;
public:
    explicit UserException(string exc_message);

    const char *what() const noexcept override;
};

class ValidationException: public exception{
private:
    string message;
public:
    explicit ValidationException(string& exc_message);

    const char *what() const noexcept override;
};

#endif //A5_A6_EXCEPTIONS_H
