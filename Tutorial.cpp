//
// Created by raulp on 4/28/2022.
//

#include "Tutorial.h"
#include <stdexcept>
#include <utility>
#include <sstream>
#include <vector>

vector<string> tokenize(const string& str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

Tutorial::Tutorial(){
    this->title="";
    this->presenter="";
    this->duration_min=0;
    this->duration_sec=0;
    this->likes=0;
    this->link="";
}

Tutorial::Tutorial(string title, string presenter, int duration_min, int duration_sec, int likes, string link) {
    if (duration_min<0 or duration_sec<0 or duration_min>59 or duration_sec>59)
        throw invalid_argument("Invalid time data");
    else
    if (likes<0)
        throw invalid_argument("Invalid number of likes");
    this->title= move(title);
    this->presenter= move(presenter);
    this->duration_min=duration_min;
    this->duration_sec=duration_sec;
    this->likes=likes;
    this->link= move(link);
}

string Tutorial::titleGetter() const{
    return this->title;
}

string Tutorial::presenterGetter() const{
    return this->presenter;
}

int Tutorial::duration_minGetter() const{
    return this->duration_min;
}

int Tutorial::duration_secGetter() const{
    return this->duration_sec;
}

int Tutorial::likesGetter() const{
    return this->likes;
}

string Tutorial::linkGetter() const{
    return this->link;
}

Tutorial::~Tutorial() =default;

string Tutorial::toString() const {
    auto str_duration_min= to_string(this->duration_min);
    auto str_duration_sec= to_string(this->duration_sec);
    auto str_likes= to_string(this->likes);
    return "Tutorial: "+this->title+" | Presenter: "+this->presenter+" | Duration: "+str_duration_min+":"+str_duration_sec+" | Link: "+this->link + "\n";
}

bool Tutorial::operator==(const Tutorial &tutorialToCheck) const {
    return this->title==tutorialToCheck.title;
}

istream & operator>>(istream&inputStream, Tutorial& tutorial){
    string line;
    getline(inputStream, line);
    vector<string> tokens;
    if(line.empty())
        return inputStream;
    tokens= tokenize(line, ',');
    tutorial.title=tokens[0];
    tutorial.presenter=tokens[1];
    tutorial.duration_min=stoi(tokens[2]);
    tutorial.duration_sec= stoi(tokens[3]);
    tutorial.likes=stoi(tokens[4]);
    tutorial.link=tokens[5];
    return inputStream;
}

ostream & operator<<(ostream& outputStream, const Tutorial& tutorialOutput){
    outputStream<< tutorialOutput.title<< ","<<tutorialOutput.presenter<<","<<to_string(tutorialOutput.duration_min)<<","<<to_string(tutorialOutput.duration_sec)<<","<<to_string(tutorialOutput.likes)<<","<< tutorialOutput.link;
    return outputStream;
}