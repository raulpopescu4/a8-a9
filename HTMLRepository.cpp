//
// Created by raulp on 5/10/2022.
//

#include "HTMLRepository.h"
#include <fstream>
#include <algorithm>


HTMLRepository::HTMLRepository(const vector<Tutorial> &watchList, const string &userFilename) {
    this->watchList=watchList;
    this->userFilename= userFilename;
}

vector<Tutorial>& HTMLRepository::getAllUserRepo() {
    return this->watchList;
}

int HTMLRepository::getNrElems() {
    return this->watchList.size();
}

int HTMLRepository::getCap() {
    return this->watchList.capacity();
}

string& HTMLRepository::getFilename() {
    return this->userFilename;
}

void HTMLRepository::addUserRepo(const Tutorial &tutorial) {
    this->watchList.push_back(tutorial);
    this->writeToFile();
}

int HTMLRepository::deleteUserRepo(int delete_index, int like) {
    if(delete_index<0 or delete_index>=this->watchList.size())
        return 0;
    Tutorial currentTutorial=this->watchList[delete_index];
    this->watchList[delete_index]= Tutorial(currentTutorial.titleGetter(), currentTutorial.presenterGetter(), currentTutorial.duration_minGetter(), currentTutorial.duration_secGetter(), currentTutorial.likesGetter()+like, currentTutorial.linkGetter());
    this->watchList.erase(this->watchList.begin()+delete_index);
    this->writeToFile();
    return 1;
}

int HTMLRepository::findByTitle(string title) {
    int search_index=-1;
    vector <Tutorial>::iterator it;
    it=find_if(this->watchList.begin(), this->watchList.end(), [&title](Tutorial& tutorial) {return tutorial.titleGetter()==title;});
    if(it!=this->watchList.end())
        search_index=it-this->watchList.begin();
    return search_index;
}

void HTMLRepository::writeToFile() {
    ofstream fout(this->userFilename);
    fout << "<!DOCTYPE html>\n<html><head><title>Watch List</title></head><body>\n";
    fout << "table border=\"1\">\n";
    fout << "<tr><td>Title</td><td>Presenter</td><td>Duration_min</td><td>Duration_sec</td><td>Likes</td><td>Link</td></tr>\n";
    for(const Tutorial& tutorial: this->watchList){
        fout <<"<tr><td>"<<tutorial.titleGetter()<<"</td><td>"<<tutorial.presenterGetter()<<"</td><td>"<< to_string(tutorial.duration_minGetter())<<"</td><td>"<< to_string(tutorial.duration_secGetter())<<"</td><td>"<< to_string(tutorial.likesGetter())<<"</td><td><a href=\""<<tutorial.linkGetter()<<"\">"<<tutorial.linkGetter()<<"</a></td>"<<endl;
    }
    fout << "</table></body></html>";
    fout.close();
}

