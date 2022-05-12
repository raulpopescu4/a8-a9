//
// Created by raulp on 4/28/2022.
//

#include "UserService.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include <algorithm>
using namespace std;

UserService::UserService(Repository &repoForAdmin, UserRepository *repoForUser): adminRepository(repoForAdmin){
    this->userRepository=repoForUser;
}

UserService::UserService(Repository &repoForAdmin) :adminRepository(repoForAdmin){}

vector<Tutorial> UserService::getAllUserService() {
    if(this->userRepository->getAllUserRepo().empty()){
        string error;
        error+=string("The list of tutorials on watchlist is empty!");
        if(!error.empty())
            throw UserException(error);
    }
    return this->userRepository->getAllUserRepo();
}

int UserService::getNrElemsUserService() {
    if (this->userRepository->getNrElems() == 0) {
        std::string error;
        error += std::string("The list of watchlist is empty!");
        if(!error.empty())
            throw UserException(error);
    }
    return this->userRepository->getNrElems();
}

int UserService::getCapUserService() {
    return this->userRepository->getCap();
}

string&UserService::getFileService() {
    return this->userRepository->getFilename();
}

int UserService::addUserService(Tutorial tutorial) {
    int length= this->userRepository->getNrElems();
    for (int i=0;i<length;i++)
    {
        string currentTitle=this->getAllUserService()[i].titleGetter();
        if (tutorial.titleGetter()==currentTitle)
            return 0;
    }
    this->userRepository->addUserRepo(tutorial);
    return 1;
}

int UserService::getFiltered(Tutorial* valid_tutorials, string presenter_filter){
    int i, counter=0, length= this->adminRepository.getNrElems();
    if (presenter_filter[0]=='\0')
        for (i=0;i<length;i++)
        {
            Tutorial tutorial= this->adminRepository.getAllRepo()[i];
            valid_tutorials[counter]=tutorial;
            counter++;
        }
    else
        for(i=0;i<length;i++)
        {
            Tutorial tutorial=this->adminRepository.getAllRepo()[i];
            if(presenter_filter==tutorial.presenterGetter()){
                valid_tutorials[counter]=tutorial;
                counter++;
            }
        }
    return counter;
}

void UserService::deleteUserService(int delete_index, int like) {
    int deletedUS=this->userRepository->deleteUserRepo(delete_index, like);
    if (deletedUS==0)
    {
        string error;
        error+=string("There is no tutorial at that given index!");
        if(!error.empty())
            throw RepositoryException(error);
    }
}

void UserService::repositoryType(const std::string& fileType) {
    if (fileType == "csv") {
        vector<Tutorial> userVector;
        string userFile = R"(Z:\FACULTA2021_2022\SEM2\OOP\a8-a9watchlist.csv)";
        auto * repo = new CSVRepository{ userVector, userFile};
        this->userRepository = repo;
    }else if (fileType == "html") {
        vector<Tutorial> userVector ;
        string userFile = R"(Z:\FACULTA2021_2022\SEM2\OOP\a8-a9\watchlist.html)";
        auto * repo = new HTMLRepository{userVector, userFile};
        this->userRepository = repo;
    } else {
        std::string error;
        error += std::string("The filename is invalid!");
        if(!error.empty())
            throw UserException(error);
    }
}

UserService::~UserService() =default;