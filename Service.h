//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_SERVICE_H
#define A5_A6_SERVICE_H
#include "Repository.h"

class Service {
private:
    Repository& repository;
public:

    explicit Service(Repository &repo);

    vector<Tutorial> getAllService();

    int getNrElemsService();

    int getCapService();

    void addService(string title, string presenter, int duration_min, int duration_sec, int likes, string link);

    void deleteService(string title);

    void updateService(string title, string new_title, string new_presenter, int new_duration_min, int new_duration_sec, int new_likes, string new_link);

    ~Service();
};


#endif //A5_A6_SERVICE_H
