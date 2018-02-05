//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Kusznik.h"
#include "../../Wojsko.h"

Kusznik::Kusznik(): Oddzial(),Zasiegowa(){
    silaAtaku_=50;
    obrona_=8;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    zasieg_=1;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Kusznik::atakuj(PolePierwszejLinii linii) {
    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
        przeciwnik->przyjmijAtak((1+getSilaAtaku_())*getLiczebnoscOddzialu_());
    }
}

void Kusznik::atakuj(PoleDrugiejLinii linii) {
    //TODO
}

void Kusznik::przyjmijAtak(double obrazenia) {
    getPole()->przyjmijAtak(*this,obrazenia);
}

const void Kusznik::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}

void Kusznik::przyjmijAtak(PolePierwszejLinii, double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+0.7*getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

void Kusznik::przyjmijAtak(PoleDrugiejLinii, double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+1.0*getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

