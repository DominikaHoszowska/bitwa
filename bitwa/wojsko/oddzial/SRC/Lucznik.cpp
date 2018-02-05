//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Lucznik.h"
#include "../../Wojsko.h"
Lucznik::Lucznik() :Oddzial(), Zasiegowa()
{
    silaAtaku_=30;
    obrona_=5;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=5;
}
void Lucznik::atakuj(PolePierwszejLinii linii) {
    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
        przeciwnik->przyjmijAtak((1+getSilaAtaku_())*getLiczebnoscOddzialu_());
    }
}

void Lucznik::atakuj(PoleDrugiejLinii linii) {
    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
        przeciwnik->przyjmijAtak((1+(getSilaAtaku_()*0.5))*getLiczebnoscOddzialu_());
    }
}

void Lucznik::przyjmijAtak(double obrazenia) {
    getPole()->przyjmijAtak(*this,obrazenia);
}

const void Lucznik::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}

void Lucznik::przyjmijAtak(PolePierwszejLinii, double obrazenia) {

    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+0.5*getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

void Lucznik::przyjmijAtak(PoleDrugiejLinii, double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}
