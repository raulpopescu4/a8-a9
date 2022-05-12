//
// Created by raulp on 5/10/2022.
//

#ifndef A5_A6_CSVREPOSITORY_H
#define A5_A6_CSVREPOSITORY_H

#include "UserRepository.h"
using namespace std;

class CSVRepository: public UserRepository{
public:
    CSVRepository(const vector<Tutorial>& watchList, const string& userFilename);

    vector<Tutorial>& getAllUserRepo() override;

    int getNrElems() override;

    int getCap() override;

    void addUserRepo(const Tutorial& tutorial) override;

    int deleteUserRepo(int delete_index, int like) override;

    int findByTitle(string title) override;

    void writeToFile() override;

    string& getFilename() override;

    ~CSVRepository();
};


#endif //A5_A6_CSVREPOSITORY_H
