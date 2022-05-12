//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_REPOSITORY_H
#define A5_A6_REPOSITORY_H
#include "Tutorial.h"
#include "Exceptions.h"
#include<vector>
using namespace std;

class Repository {
private:
    vector<Tutorial> adminRepositoryVector;
    string tutorialFilename;
public:
    void loadTutorialsFromFile();

    void writeTutorialsToFile();

    explicit Repository(vector<Tutorial>&repo_vector, string& tutorial_filename);

    void initialiseRepo();

    vector<Tutorial>& getAllRepo();

    int getNrElems();

    int getCap();

    void addRepo(const Tutorial& tutorial);

    int findByTitle(const string& title);

    void deleteRepo(int delete_index);

    void updateRepo(int update_index, const Tutorial& new_tutorial);

    ~Repository();
};


#endif //A5_A6_REPOSITORY_H
