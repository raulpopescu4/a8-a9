//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_USERREPOSITORY_H
#define A5_A6_USERREPOSITORY_H
#include "Tutorial.h"
#include <vector>
#include <Exceptions.h>


class UserRepository {
protected:
    vector<Tutorial> watchList;
    string userFilename;
public:
    explicit UserRepository(vector<Tutorial>& the_watchList);

    UserRepository();

    virtual vector<Tutorial>& getAllUserRepo()=0;

    virtual int getNrElems()=0;

    virtual int getCap()=0;

    virtual void addUserRepo(const Tutorial& tutorial)=0;

    virtual int findByTitle(string title)=0;

    virtual int deleteUserRepo(int delete_index, int like)=0;

    virtual void writeToFile()=0;

    virtual string& getFilename()=0;

    ~UserRepository();
};


#endif //A5_A6_USERREPOSITORY_H
