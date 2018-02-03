//
// Created by Dominika on 02.02.2018.
//

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
    //TODO

}

