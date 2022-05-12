//
// Created by raulp on 4/28/2022.
//

#include "Repository.h"
#include "Tutorial.h"
#include <algorithm>
#include <fstream>

Repository::Repository(vector<Tutorial>& repo_vector, string& tutorial_filename) {
    this->adminRepositoryVector=repo_vector;
    this->tutorialFilename=tutorial_filename;
}

void Repository::loadTutorialsFromFile() {
    if(!this->tutorialFilename.empty())
    {
        Tutorial tutorialFromFile;
        ifstream fin(this->tutorialFilename);
        while(fin>>tutorialFromFile)
        {
            if(find(this->adminRepositoryVector.begin(),this->adminRepositoryVector.end(), tutorialFromFile)==this->adminRepositoryVector.end())
                this->adminRepositoryVector.push_back(tutorialFromFile);
        }
        fin.close();
    }
}

void Repository::writeTutorialsToFile() {
    if(!this->tutorialFilename.empty()){
        ofstream fout(this->tutorialFilename);
        for(const Tutorial& tutorial: this->adminRepositoryVector){
            fout << tutorial<<"\n";
        }
        fout.close();
    }
}


void Repository::initialiseRepo() {
    this->loadTutorialsFromFile();
}

vector<Tutorial>& Repository::getAllRepo() {
    if(this->adminRepositoryVector.empty()){
        string error;
        error+=string("The database is empty!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    return this->adminRepositoryVector;
}

int Repository::getNrElems() {
    if(this->adminRepositoryVector.empty())
    {
        string error;
        error+=string("The database is empty!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    return this->adminRepositoryVector.size();
}

int Repository::getCap() {
    return this->adminRepositoryVector.capacity();
}

void Repository::addRepo(const Tutorial &tutorial) {
    this->adminRepositoryVector.push_back(tutorial);
    this->writeTutorialsToFile();
}

int Repository::findByTitle(const string& title) {
    int searched_index=-1;
    vector<Tutorial>::iterator it;
    it= find_if(this->adminRepositoryVector.begin(), this->adminRepositoryVector.end(), [&title](Tutorial& tutorial){return tutorial.titleGetter()==title;});
    if(it!=this->adminRepositoryVector.end())
        searched_index=it-this->adminRepositoryVector.begin();
    return searched_index;
}

void Repository::deleteRepo(int delete_index) {
    this->adminRepositoryVector.erase(this->adminRepositoryVector.begin()+delete_index);
    this->writeTutorialsToFile();
}

void Repository::updateRepo(int update_index, const Tutorial &new_tutorial) {
    this->adminRepositoryVector[update_index]=new_tutorial;
    this->writeTutorialsToFile();
}

Repository::~Repository() =default;
