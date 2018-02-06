//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <vector>
#include <iostream>
#include "Gra.h"


using symbole_wojska_t = std::vector<std::vector<std::vector<char>>>;

Gra::Gra(unsigned int liczbaTur, unsigned int dlugoscLinii,const symbole_wojska_t& wojska) :
    liczbaTur_(liczbaTur),
    poleBitwy_(dlugoscLinii),
    pierwszyGracz_(0, wojska.at(0), &poleBitwy_),
    drugiGracz_(1, wojska.at(1), &poleBitwy_)
{
    dlugoscLinii_=dlugoscLinii;
    poleBitwy_.setGra(this);
}

bool Gra::czyKoniec() {

    if(pierwszyGracz_.czyPuste())
    {
        std::cout<<"Wygrał drugi gracz!!!";
        return true;
    }
    if(drugiGracz_.czyPuste())
    {
        std::cout<<"Wygrał pierwszy gracz!!!";
        return true;
    }
    if(nrTury_==liczbaTur_)
    {
        std::cout<<"REMIS";
        return true;
    }
    return false;

}

void Gra::rozegrajTure() {
    nrTury_+=1;
    pierwszyGracz_.wyslijWsparcie();
    drugiGracz_.wyslijWsparcie();

    pierwszyGracz_.wykonajAtak();
    drugiGracz_.wykonajAtak();

    pierwszyGracz_.wycofajWsparcie();
    drugiGracz_.wycofajWsparcie();

    pierwszyGracz_.przeliczStraty();
    drugiGracz_.przeliczStraty();
    poleBitwy_.zmianaMorale();
    poleBitwy_.usunPoleglych();
    poleBitwy_.konsolidacja(0);
    poleBitwy_.konsolidacja(1);
    wypisz();

}

void Gra::wypisz() {
    wypiszPrzerywnik();
    std::cout<<"Tura "<<this->nrTury_<<" z "<<liczbaTur_<<std::endl;
    this->poleBitwy_.wypisz();
    wypiszPrzerywnik();

}

void Gra::wypiszPrzerywnik()
{

    for (unsigned int a=0;a<5*(this->dlugoscLinii_)+12;a++)
        std::cout<<'-';
    std::cout<<std::endl;
}

unsigned int Gra::getDlugoscLinii() const {
    return dlugoscLinii_;
}

 Gracz &Gra::getPierwszyGracz_()  {
    return pierwszyGracz_;
}

Gracz &Gra::getDrugiGracz_()  {
    return drugiGracz_;
}
