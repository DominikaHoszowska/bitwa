//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Miecznik.h"
#include "../../Wojsko.h"

Miecznik::Miecznik(): Oddzial(), Zwarcie()
{
    silaAtaku_=30;
    obrona_=20;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=1;
}

void Miecznik::atakuj(PolePierwszejLinii& linii) {

    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
        przeciwnik->przyjmijAtak((1+getSilaAtaku_())*getLiczebnoscOddzialu_());
    }
}

void Miecznik::przyjmijAtak(double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }

}

const void Miecznik::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}


