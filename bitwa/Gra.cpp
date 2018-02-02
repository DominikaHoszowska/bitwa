//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <vector>
#include "Gra.h"


using symbole_wojska_t = std::vector<std::vector<std::vector<char>>>;

Gra::Gra(unsigned int liczbaTur, unsigned int dlugoscLinii,const symbole_wojska_t& wojska) :
    liczbaTur_(liczbaTur),
    poleBitwy_(dlugoscLinii),
    pierwszyGracz_(0, wojska.at(0), &poleBitwy_),
    drugiGracz_(1, wojska.at(1), &poleBitwy_)
{
}

bool Gra::czyKoniec() {

    //TODO

    return false;

}

void Gra::rozegrajTure() {

    pierwszyGracz_.wyslijWsparcie();
    drugiGracz_.wyslijWsparcie();

    pierwszyGracz_.wykonajAtak();
    drugiGracz_.wykonajAtak();

    pierwszyGracz_.wycofajWsparcie();
    drugiGracz_.wycofajWsparcie();

    pierwszyGracz_.zakonczTure();
    drugiGracz_.zakonczTure();

}

