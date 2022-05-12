//
// Created by raulp on 5/10/2022.
//

#ifndef A5_A6_HTMLREPOSITORY_H
#define A5_A6_HTMLREPOSITORY_H
#include "UserRepository.h"

using namespace std;

class HTMLRepository: public UserRepository{
public:
    HTMLRepository(const vector<Tutorial>& watchList, const string& userFilename);

    vector<Tutorial>& getAllUserRepo() override;

    int getNrElems() override;

    int getCap() override;

    void addUserRepo(const Tutorial& tutorial) override;

    int deleteUserRepo(int delete_index, int like) override;

    int findByTitle(string title) override;

    void writeToFile() override;

    string& getFilename() override;

    ~HTMLRepository();
};


#endif //A5_A6_HTMLREPOSITORY_H
