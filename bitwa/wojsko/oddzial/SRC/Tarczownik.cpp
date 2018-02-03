//
// Created by Dominika on 02.02.2018.
//

#include "../Headers/Tarczownik.h"

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
