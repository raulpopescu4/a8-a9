//
// Created by raulp on 4/28/2022.
//

#include "Service.h"
#include <iterator>
#include <algorithm>
using namespace std;

Service::Service(Repository &repo) : repository(repo){
}

vector<Tutorial> Service::getAllService() {
    return this->repository.getAllRepo();
}

int Service::getNrElemsService() {
    return this->repository.getNrElems();
}

int Service::getCapService() {
    return this->repository.getCap();
}

void Service::addService(string title, string presenter, int duration_min, int duration_sec, int likes, string link) {
    int existing=this->repository.findByTitle(title);
    if (existing!=-1)
    {
        string error;
        error+=string("The tutorial already exists");
        if(!error.empty())
            throw RepositoryException(error);
    }
    Tutorial tutorial =Tutorial(title, presenter, duration_min, duration_sec, likes, link);
    this->repository.addRepo(tutorial);
}

void Service::deleteService(string title) {
    int delete_index= this->repository.findByTitle(title);
    if(delete_index==-1)
    {
        string error;
        error+=string ("The tutorial doesn't exist");
        if(!error.empty()){
            throw RepositoryException(error);
        }
    }
    this->repository.deleteRepo(delete_index);
}


void Service::updateService(string title, string new_title, string new_presenter, int new_duration_min, int new_duration_sec, int new_likes, string new_link) {
    int update_index=this->repository.findByTitle(title);
    if(update_index==-1) {
        string error;
        error+=string ("The tutorial doesn't exist!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    Tutorial new_tutorial=Tutorial(new_title, new_presenter, new_duration_min, new_duration_sec, new_likes, new_link);
    this->repository.updateRepo(update_index, new_tutorial);
}

Service::~Service() =default;