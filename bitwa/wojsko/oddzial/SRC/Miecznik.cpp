//
// Created by Dominika on 02.02.2018.
//

#include "../Headers/Miecznik.h"

Miecznik::Miecznik(): Oddzial(), Zwarcie()
{
    silaAtaku_=30;
    obrona_=20;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=1;
}

void Miecznik::atakuj(PolePierwszejLinii linii) {
    //TODO

}


