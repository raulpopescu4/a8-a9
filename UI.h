//
// Created by raulp on 4/29/2022.
//

#ifndef A5_A6_UI_H
#define A5_A6_UI_H
#include "Service.h"
#include "UserService.h"
#include "TutorialValidator.h"


class UI {
private:
    Service & service;
    UserService & userService;
    TutorialValidator & validator;
public:
    UI(Service&service, UserService&userService, TutorialValidator& validator1);

    static bool validateString(string input);

    void addUi();

    void deleteUi();

    void updateUi();

    void listAll();

    void listAllFiltered();

    void deleteFromWatchlist();

    void listWatchList();

    void openFile();

    static void printAdministratorSubmenu();

    static void printUserSubmenu();

    void AdministratorMode();

    void UserMode();

    static void printMenu();

    void start();

    ~UI();
};


#endif //A5_A6_UI_H
