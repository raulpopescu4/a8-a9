//
// Created by raulp on 4/28/2022.
//

#ifndef A5_A6_TUTORIAL_H
#define A5_A6_TUTORIAL_H
#include <string>
using namespace std;

class Tutorial {
private:
    string title;
    string presenter;
    int duration_min;
    int duration_sec;
    int likes;
    string link;
public:

    Tutorial();

    explicit Tutorial(string title, string presenter, int duration_min, int duration_sec, int likes, string link);

    string titleGetter() const;

    string presenterGetter() const;

    int duration_minGetter() const;

    int duration_secGetter() const;

    int likesGetter() const;

    string linkGetter() const;

    ~Tutorial();

    string toString() const;

    bool operator==(const Tutorial& tutorialToCheck) const;

    friend istream & operator>>(istream& inputStream, Tutorial& tutorial);

    friend ostream & operator<<(ostream& outputStream, const Tutorial& tutorialOutput);

};


#endif //A5_A6_TUTORIAL_H
