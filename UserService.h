//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_USERSERVICE_H
#define A5_A6_USERSERVICE_H
#include "Repository.h"
#include "UserRepository.h"

class UserService {
private:
    Repository& adminRepository;
    UserRepository* userRepository;
public:

    UserService(Repository & repoForAdmin, UserRepository * repoForUser);

    explicit UserService(Repository& repoForAdmin);

    vector<Tutorial> getAllUserService();

    int getNrElemsUserService();

    int getCapUserService();

    int addUserService(Tutorial tutorial);

    int getFiltered(Tutorial* valid_tutorials, string presenter_filter);

    void deleteUserService(int delete_index, int like);

    void repositoryType(const string& fileType);

    string & getFileService();

    ~UserService();
};


#endif //A5_A6_USERSERVICE_H
