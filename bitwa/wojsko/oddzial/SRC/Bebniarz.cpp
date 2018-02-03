//
// Created by Dominika on 02.02.2018.
//

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
