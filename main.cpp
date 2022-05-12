#include <iostream>
#include <Repository.h>
#include <UserRepository.h>
#include <Service.h>
#include <UserService.h>
#include <UI.h>


using namespace std;

int main(){
    vector<Tutorial> adminRepoVector;
    adminRepoVector.reserve(10);
    string filename=R"(Z:\FACULTA2021_2022\SEM2\OOP\a8-a9\tutorials.txt)";
    Repository repo{adminRepoVector, filename};
    repo.initialiseRepo();
    Service service{repo};
    UserService userService{repo};
    TutorialValidator validator{};
    UI ui{service, userService, validator};
    ui.start();

    return 0;
}