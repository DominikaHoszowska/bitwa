//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Halabardzista.h"
#include "../../Wojsko.h"
#include "../Headers/Konny.h"

Halabardzista::Halabardzista():Oddzial(),Zwarcie() {
    silaAtaku_=40;
    obrona_=20;
    wytrzymalosc_=40;
    liczebnoscOddzialu_=150;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Halabardzista::atakuj(PolePierwszejLinii& pole) {
    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
            przeciwnik->przyjmijAtakW(this);

    }
}

const void Halabardzista::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();
}

void Halabardzista::atakuj(Konny &przeciwnik) {
    przeciwnik.przyjmijAtak((1+1.5*getSilaAtaku_())*getLiczebnoscOddzialu_());
}

void Halabardzista::atakuj(Oddzial &przeciwnik) {
    przeciwnik.przyjmijAtak((1+getSilaAtaku_())*getLiczebnoscOddzialu_());

}

