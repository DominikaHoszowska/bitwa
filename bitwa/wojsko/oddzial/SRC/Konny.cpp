//
// Created by Dominika on 02.02.2018.
//

#include <iostream>
#include "../Headers/Konny.h"



Konny::Konny(): Oddzial(),Zwarcie(){
    silaAtaku_=50;
    obrona_=10;
    wytrzymalosc_=70;
    liczebnoscOddzialu_=100;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Konny::atakuj(PolePierwszejLinii linii) {
    //TODO

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
