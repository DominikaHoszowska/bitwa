//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Bebniarz.h"
#include "../Headers/Oddzial.h"

double Bebniarz::zmianaMorale() {
    return  1.5;
}

double Bebniarz::zmianaObrona() {
    return 1.0;
}

void Bebniarz::atakuj() {
//nie atakuje
}

Bebniarz::Bebniarz(): Oddzial(),Zasiegowa(),Wsparcie(){
    silaAtaku_=40;
    obrona_=20;
    wytrzymalosc_=40;
    liczebnoscOddzialu_=150;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Bebniarz::przyjmijAtak(double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }}

void Bebniarz::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}
