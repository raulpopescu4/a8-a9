//
// Created by raulp on 4/29/2022.
//

#ifndef A5_A6_TUTORIALVALIDATOR_H
#define A5_A6_TUTORIALVALIDATOR_H
#include "Tutorial.h"
#include <algorithm>
#include "Exceptions.h"

class TutorialValidator {
public:
    TutorialValidator();

    bool validateString(const string&input);

    void validateTitle(const string& title);

    void validatePresenter(const string& presenter);

    void validateDurationMinString(const string& duration_min);

    void validateDurationSecString(const string& duration_sec);

    void validateLikesString(const string& likes);

    void validateLink(const string& link);

    void validateDurationMin(int duration_min);

    void validateDurationSec(int duration_sec);

    void validateLikes(int likes);

    ~TutorialValidator();
};


#endif //A5_A6_TUTORIALVALIDATOR_H
