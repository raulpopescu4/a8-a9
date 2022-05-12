//
// Created by raulp on 4/29/2022.
//

#include "UI.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

UI::UI(Service &service, UserService &userService, TutorialValidator &validator1) : service(service), userService(userService), validator(validator1){}

bool UI::validateString(string input) {
    for(int i=0;i<input.length();i++)
        if(isdigit(input[i])!= false)
            return false;
    return true;
}

void UI::addUi() {
    cout<<"Add a new tutorial"<< endl;
    string title, presenter, link, duration_min_s, duration_sec_s, likes_s;
    int duration_min, duration_sec, likes;
    while (true)
    {
        try{
            cout<<"Enter the title: "<<endl;
            getline(cin, title);
            this->validator.validateTitle(title);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    while (true)
    {
        try{
            cout<<"Enter the presenter: "<<endl;
            getline(cin, presenter);
            this->validator.validatePresenter(presenter);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the duration(minutes part): "<<endl;
            getline(cin, duration_min_s);
            this->validator.validateDurationMinString(duration_min_s);
            duration_min= stoi(duration_min_s);
            this->validator.validateDurationMin(duration_min);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the duration(seconds part): "<<endl;
            getline(cin, duration_sec_s);
            this->validator.validateDurationSecString(duration_sec_s);
            duration_sec= stoi(duration_sec_s);
            this->validator.validateDurationSec(duration_sec);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the number of likes: "<<endl;
            getline(cin, likes_s);
            this->validator.validateLikesString(likes_s);
            likes= stoi(likes_s);
            this->validator.validateLikes(likes);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while (true)
    {
        try{
            cout<<"Enter the link: "<<endl;
            getline(cin, link);
            this->validator.validateLink(link);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }

    try {
        Tutorial tutorial=Tutorial(title, presenter, duration_min, duration_sec, likes, link);
        this->service.addService(title, presenter, duration_min, duration_sec, likes, link);
        cout <<"Tutorial added successfully!";
    }
    catch (RepositoryException&ex)
    {
        cout<<ex.what()<< endl;
    }

}

void UI::deleteUi() {
    cout<<"Delete a tutorial "<< endl;
    string title;
    while (true)
    {
        try{
            cout<<"Enter the title: "<<endl;
            getline(cin, title);
            this->validator.validateTitle(title);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    try{
        this->service.deleteService(title);
        cout << "Tutorial successfully deleted"<< endl;
    }
    catch(RepositoryException&ex){
        cout<< ex.what()<<endl;
    }
}

void UI::updateUi() {
    cout<<"Update a tutorial"<< endl;
    string old_title;
    string title, presenter, link, duration_min_s, duration_sec_s, likes_s;
    int duration_min, duration_sec, likes;

    while (true)
    {
        try{
            cout<<"Enter the old title: "<<endl;
            getline(cin, old_title);
            this->validator.validateTitle(old_title);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    while (true)
    {
        try{
            cout<<"Enter the title: "<<endl;
            getline(cin, title);
            this->validator.validateTitle(title);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    while (true)
    {
        try{
            cout<<"Enter the presenter: "<<endl;
            getline(cin, presenter);
            this->validator.validatePresenter(presenter);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the duration(minutes part): "<<endl;
            getline(cin, duration_min_s);
            this->validator.validateDurationMinString(duration_min_s);
            duration_min= stoi(duration_min_s);
            this->validator.validateDurationMin(duration_min);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the duration(seconds part): "<<endl;
            getline(cin, duration_sec_s);
            this->validator.validateDurationSecString(duration_sec_s);
            duration_sec= stoi(duration_sec_s);
            this->validator.validateDurationSec(duration_sec);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while(true){
        try{
            cout<<"Enter the number of likes: "<<endl;
            getline(cin, likes_s);
            this->validator.validateLikesString(likes_s);
            likes= stoi(likes_s);
            this->validator.validateLikes(likes);
            break;
        }
        catch (ValidationException&ex){
            cout << ex.what()<<endl;
        }
    }
    while (true)
    {
        try{
            cout<<"Enter the link: "<<endl;
            getline(cin, link);
            this->validator.validateLink(link);
            break;
        }
        catch (ValidationException&ex){
            cout<< ex.what()<< endl;
        }
    }


    try {
        Tutorial tutorial=Tutorial(title, presenter, duration_min, duration_sec, likes, link);
        this->service.updateService(old_title, title, presenter, duration_min, duration_sec, likes, link);
        cout <<"Tutorial updated successfully!";
    }
    catch (RepositoryException&ex)
    {
        cout<<ex.what()<< endl;
    }
}

void UI::listAll() {
    vector<Tutorial> tutorials;
    tutorials=this->service.getAllService();
    int index=0;
    for (const Tutorial&tutorial: tutorials)
    {
        cout << index+1<<". "<<tutorial.toString()<<endl;
        index++;
    }
}

void UI::listAllFiltered() {
    cout << "Enter the presenter name:"<< endl;
    string presenter_filter;
    getline(cin, presenter_filter);
    Tutorial* filtered_tutorials=new Tutorial[101];
    int counter=this->userService.getFiltered(filtered_tutorials, presenter_filter);
    if (counter>0)
    {
        cout << filtered_tutorials[0].toString()<< endl;
        system(("vivaldi.exe " + filtered_tutorials[0].linkGetter()).c_str());
    }
    int i=0;
    string command;
    while (i<counter)
    {
        cout << "Do you want to see the next tutorial, do you want to add the current one to the watchlist, or do you want to exit? input:(next/add/exit)"<<endl;
        getline(cin, command);
        while(command!="exit"&& command!="next"&&command!="add")
        {
            cout << "input:(next/add/exit)"<< endl;
            getline(cin, command);
        }
        if (command=="exit"){
            cout << "You have just exited watching the tutorials one by one"<< endl;
            break;
        }
        else
        if (command=="add")
        {
            int added=this->userService.addUserService(filtered_tutorials[i]);
            if(added)
                cout << "This tutorial will be added to your watchlist!"<< endl;
            else
                throw "You already have it in your playlist";
        }
        else
        {
            if (i==counter-1)
                i=0;
            else
                i++;
            cout << filtered_tutorials[i].toString()<< endl;
        }
    }
}

void UI::deleteFromWatchlist() {
    this->listWatchList();
    cout << endl<< "Choose the index of the tutorial you want to delete from the watchlist"<< endl;
    string deleteIndex_s, like_s;
    int deleteIndex=-1, like=-1;
    getline(cin, deleteIndex_s);
    if (!validateString(deleteIndex_s)&&deleteIndex_s.length()!=0)
        deleteIndex=stoi(deleteIndex_s);
    cout << "Choose to like it or not; input (0/1): "<< endl;
    getline(cin, like_s);
    if (!validateString(like_s)&&like_s.length()!=0)
        like= stoi(like_s);
    while(like!=0&&like!=1)
    {
        like=-1;
        cout<< "You didn`t choose whether to like it or not; pick between 0 and 1"<< endl;
        getline(cin, like_s);
        if(!validateString(like_s)&&like_s.length()!=0)
            like=stoi(like_s);
    }
    try{
        this->userService.deleteUserService(deleteIndex-1, like);
        cout << "Tutorial deleted from the watchlist!";
    }
    catch(RepositoryException&ex){
        cout << ex.what()<< endl;
    }
}

void UI::listWatchList() {
    cout<< "Here is your watchlist: "<< endl;
    vector<Tutorial>watchlist;
    watchlist=this->userService.getAllUserService();
    int index=0;
    for (const Tutorial&tutorial: watchlist){
        cout <<index+1<<". "<<tutorial.toString()<<endl;
        index++;
    }
}

void UI::openFile(){
    string link=string("start ").append(this->userService.getFileService());
    system(link.c_str());
}

void UI::printAdministratorSubmenu() {
    cout<<"ADMINISTRATOR MENU: "<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"1. List all the tutorials."<<endl;
    cout<<"2. Add a new tutorial."<<endl;
    cout<<"3. Delete a tutorial."<<endl;
    cout<<"4. Update a tutorial."<<endl;
    cout<<"Choose an option: "<<endl;
}

void UI::printUserSubmenu() {
    cout<<"USER MENU: "<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"1. See all the tutorials in the database that have a given presenter, one by one."<<endl;
    cout<<"2. Delete a tutorial from the watchlist."<<endl;
    cout<<"3. See the watch list."<<endl;
    cout<<"4. See the watch list file."<<endl;
    cout<<"Choose an option: "<<endl;
}

void UI::AdministratorMode() {
    cout<<"~You entered the administrator mode~"<<endl;
    bool done = false;
    while (!done) {
        try {
            printAdministratorSubmenu();
            string option;
            getline(cin, option);
            if (option == "0") {
                done = true;
                cout << "Exiting admin mode..." << endl;
            } else if (option == "1")
                this->listAll();
            else if (option == "2")
                this->addUi();
            else if (option == "3")
                this->deleteUi();
            else if (option == "4")
                this->updateUi();
            else
                cout << "Bad input!"<<endl;
        }catch (ValidationException&ex) {
            cout<<ex.what()<<endl;
        }catch(RepositoryException&ex){
            cout << ex.what()<<endl;
        }
    }
}

void UI::UserMode() {
    cout<<"~You entered the user mode~"<<endl;
    bool done = false;
    while(!done) {
        try {
            printUserSubmenu();
            string option;
            getline(cin, option);
            if (option == "0") {
                done = true;
                cout<<"Exiting user mode..."<<endl;
            }
            else if (option == "1")
                this->listAllFiltered();
            else if (option == "2")
                this->deleteFromWatchlist();
            else if (option == "3")
                this->listWatchList();
            else if (option == "4")
                this->openFile();
            else
                cout<<"Bad input!"<<endl;
        }catch (ValidationException&ex) {
            cout<<ex.what()<<endl;
        }catch (UserException&ex) {
            cout<<ex.what()<<endl;
        }
        catch(RepositoryException&ex){
            cout << ex.what()<<endl;
        }
    }
}

void UI::printMenu() {
    cout<<"MENU:"<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"1. Administrator mode."<<endl;
    cout<<"2. User mode."<<endl;
    cout<<"Choose an option: "<<endl;
}

void UI::start() {
    cout<<"Manage your c++ tutorials"<<endl;
    bool done = false;
    int usermode=0;
    while (!done) {
        printMenu();
        string option;
        getline(cin,option);
        if (option == "1")
            AdministratorMode();
        else if (option == "2"){
            if(usermode==0)
            {
                cout<<"Enter the type of the file in which you want to save the watchlist(csv or html):"<<endl;
                string fileType;
                while(true){
                    try{
                        getline(cin, fileType);
                        this->userService.repositoryType(fileType);
                        break;
                    }
                    catch(UserException&ex){
                        cout << ex.what()<<endl;
                    }
                }
                usermode=1;
            }
            UserMode();
        }

        else if (option == "0") {
            done = true;
            cout << "Goodbye!" << endl;
        }else
            cout<<"Bad input!"<<endl;
    }


}

UI::~UI() = default;