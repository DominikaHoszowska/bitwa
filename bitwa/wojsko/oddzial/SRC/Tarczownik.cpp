//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Tarczownik.h"
#include "../../Wojsko.h"
double Tarczownik::zmianaMorale() {
    return 1.0;
}

double Tarczownik::zmianaObrona() {
    return 1.5;
}

void Tarczownik::atakuj() {
//nie atakuje
}

Tarczownik::Tarczownik(): Oddzial(),Zwarcie(),Wsparcie()
{
    silaAtaku_=0;
    obrona_=20;
    wytrzymalosc_=100;
    liczebnoscOddzialu_=100;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=2;
}

void Tarczownik::przyjmijAtak(double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

const void Tarczownik::wypisz() {

    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}

void Tarczownik::wycofajWsparcie(Oddzial *oddzial) {
    oddzial->wycofajWsparcie(*this);
}

void Tarczownik::przesunSzeregi(PoleBitwy *bitwy) {
    bitwy->przesunSzeregi(*this);
}

