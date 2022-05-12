//
// Created by raulp on 5/10/2022.
//

#include "CSVRepository.h"
#include <fstream>
#include <algorithm>

CSVRepository::CSVRepository(const vector<Tutorial> &watchList, const string &userFilename) {
    this->watchList=watchList;
    this->userFilename= userFilename;
}

vector<Tutorial>& CSVRepository::getAllUserRepo() {
    return this->watchList;
}

int CSVRepository::getNrElems() {
    return this->watchList.size();
}

int CSVRepository::getCap() {
    return this->watchList.capacity();
}

string& CSVRepository::getFilename() {
    return this->userFilename;
}

void CSVRepository::addUserRepo(const Tutorial &tutorial) {
    this->watchList.push_back(tutorial);
    this->writeToFile();
}

int CSVRepository::deleteUserRepo(int delete_index, int like) {
    if(delete_index<0 or delete_index>=this->watchList.size())
        return 0;
    Tutorial currentTutorial=this->watchList[delete_index];
    this->watchList[delete_index]= Tutorial(currentTutorial.titleGetter(), currentTutorial.presenterGetter(), currentTutorial.duration_minGetter(), currentTutorial.duration_secGetter(), currentTutorial.likesGetter()+like, currentTutorial.linkGetter());
    this->watchList.erase(this->watchList.begin()+delete_index);
    this->writeToFile();
    return 1;
}

int CSVRepository::findByTitle(string title) {
    int search_index=-1;
    vector <Tutorial>::iterator it;
    it=find_if(this->watchList.begin(), this->watchList.end(), [&title](Tutorial& tutorial) {return tutorial.titleGetter()==title;});
    if(it!=this->watchList.end())
        search_index=it-this->watchList.begin();
    return search_index;
}

void CSVRepository::writeToFile() {
    ofstream fout(this->userFilename);
    if(!this->watchList.empty()){
        for(const Tutorial& tutorial: this->watchList)
            fout << tutorial<<endl;
    }
    fout.close();
}

CSVRepository::~CSVRepository() =default;