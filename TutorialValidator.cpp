//
// Created by raulp on 4/29/2022.
//

#include "TutorialValidator.h"

TutorialValidator::TutorialValidator() =default;

bool TutorialValidator::validateString(const string &input) {
    if(all_of(input.cbegin(), input.cend(),[](char i){return !isdigit(i);}));
}

void TutorialValidator::validateTitle(const string &title) {
    string errors;
    if(!validateString(title))
        errors+=string("The title input contains digits!");
    if(title.length()==0)
        errors+=string("The title input is empty!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validatePresenter(const string &presenter) {
    string errors;
    if(!validateString(presenter))
        errors+=string("The presenter input contains digits!");
    if(presenter.length()==0)
        errors+=string("The presenter input is empty!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateDurationMinString(const string &duration_min) {
    string errors;
    if(duration_min.empty())
        errors+=string("The duration_min input is empty!");
    if(duration_min.find_first_not_of("0123456789")!=string::npos)
        errors+=string("The duration_min input has non-digit characters!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateDurationSecString(const string &duration_sec) {
    string errors;
    if(duration_sec.empty())
        errors+=string("The duration_sec input is empty!");
    if(duration_sec.find_first_not_of("0123456789")!=string::npos)
        errors+=string("The duration_sec input has non-digit characters!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateLikesString(const string &likes) {
    string errors;
    if(likes.empty())
        errors+=string("The likes input is empty!");
    if(likes.find_first_not_of("0123456789")!=string::npos)
        errors+=string("The likes input has non-digit characters!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateLink(const string &link) {
    string errors;
    if(link.length()==0)
        errors+=string("The link input is empty!");
    if(link.find("www")== string::npos)
        errors+=string("The link is not a valid one!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateDurationMin(int duration_min) {
    string errors;
    if(duration_min<0)
        errors+=string("Duration_min cannot be smaller than 0!");
    if(duration_min>59)
        errors+=string("Duration_min cannot be higher that 59!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateDurationSec(int duration_sec) {
    string errors;
    if(duration_sec<0)
        errors+=string("Duration_sec cannot be smaller than 0!");
    if(duration_sec>59)
        errors+=string("Duration_sec cannot be higher that 59!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void TutorialValidator::validateLikes(int likes) {
    string errors;
    if(likes<0)
        errors+=string("Likes cannot be smaller than 0!");
    if(!errors.empty())
        throw ValidationException(errors);
}

TutorialValidator::~TutorialValidator() =default;