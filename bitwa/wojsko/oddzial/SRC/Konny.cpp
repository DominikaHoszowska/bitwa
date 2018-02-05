//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Konny.h"
#include "../../Wojsko.h"


Konny::Konny(): Oddzial(),Zwarcie(){
    silaAtaku_=50;
    obrona_=10;
    wytrzymalosc_=70;
    liczebnoscOddzialu_=100;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Konny::atakuj(PolePierwszejLinii& linii) {
    Oddzial* przeciwnik=getWojsko()->znajdzPrzeciwnika(*this);
    if(przeciwnik!= nullptr)
    {
        przeciwnik->przyjmijAtakW(this);

    }
}

void Konny::przyjmijAtak(double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

const void Konny::wypisz() {
    std::cout<<this->OZNACZENIE;
    wypiszLiczebnosc();


}

void Konny::przyjmijAtakW(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}

void Konny::atakuj(Zasiegowa &przeciwnik) {
    przeciwnik.przyjmijAtak((1+1.25*getSilaAtaku_())*getLiczebnoscOddzialu_());

}

void Konny::atakuj(Oddzial &przeciwnik) {
    przeciwnik.przyjmijAtak((1+getSilaAtaku_())*getLiczebnoscOddzialu_());

}
