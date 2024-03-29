//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <iostream>
#include "../Headers/Oddzial.h"
#include "../../Wojsko.h"
#include "../Headers/Tarczownik.h"
#include "../Headers/Bebniarz.h"
using  std::cout;

void Oddzial::wspieraj() {
}



void Oddzial::wycofajWsparcie() {

    while (!wsparcie_.empty())
    {
        Wsparcie* wspierajacy=wsparcie_.front();
        wsparcie_.pop_front();
        wspierajacy->wycofajWsparcie(this);

    }

}

Pole *Oddzial::getPole()  {
    return pole_;
}

void Oddzial::setPole(Pole *pole_) {
    Oddzial::pole_ = pole_;
}

Wojsko *Oddzial::getWojsko() const {
    return wojsko_;
}

void Oddzial::setWojsko(Wojsko *wojsko_) {
    Oddzial::wojsko_ = wojsko_;
}

double Oddzial::getStraty() const {
    return straty_;
}

void Oddzial::setStraty(double straty_) {
    Oddzial::straty_ = straty_;
}

double Oddzial::getMorale() const {
    return morale_;
}

void Oddzial::setMorale(double morale_) {
    Oddzial::morale_ = morale_;
}

void Oddzial::dodajWspierajacego(Wsparcie *wspierajacy) {
    wsparcie_.push_back(wspierajacy);
    morale_*=wspierajacy->zmianaMorale();
    obrona_*=wspierajacy->zmianaObrona();
}

int Oddzial::getSilaAtaku_() const {
    return silaAtaku_;
}

void Oddzial::setSilaAtaku_(int silaAtaku_) {
    Oddzial::silaAtaku_ = silaAtaku_;
}

double Oddzial::getObrona_() const {
    return obrona_;
}

void Oddzial::setObrona_(double obrona_) {
    Oddzial::obrona_ = obrona_;
}

int Oddzial::getWytrzymalosc_() const {
    return wytrzymalosc_;
}

void Oddzial::setWytrzymalosc_(int wytrzymalosc_) {
    Oddzial::wytrzymalosc_ = wytrzymalosc_;
}

int Oddzial::getLiczebnoscOddzialu_() const {
    return liczebnoscOddzialu_;
}

void Oddzial::setLiczebnoscOddzialu_(int liczebnoscOddzialu_) {
    Oddzial::liczebnoscOddzialu_ = liczebnoscOddzialu_;
}

int Oddzial::getLiczebnoscPoczatkowa() const {
    return liczebnoscPoczatkowa;
}

void Oddzial::setLiczebnoscPoczatkowa(int liczebnoscPoczatkowa) {
    Oddzial::liczebnoscPoczatkowa = liczebnoscPoczatkowa;
}

unsigned int Oddzial::getZasieg_() const {
    return zasieg_;
}



Oddzial::Oddzial(){
    morale_=0;
    straty_=0;
}

void Oddzial::atakuj() {
    getPole()->czyMogeAtakowac(this);
}

void Oddzial::atakuj(PolePierwszejLinii&) {

}

void Oddzial::atakuj(PoleDrugiejLinii&) {

}

void Oddzial::przyjmijAtak(double obrazenia) {
    double straty=obrazenia*(1-2*getMorale()/(1-getMorale()))
                  /getWytrzymalosc_()/(1+getObrona_());
    if(straty>0)
    {
        straty+=getStraty();
        setStraty(straty);
    }
}

const void Oddzial::wypisz() {

}

void Oddzial::wypiszLiczebnosc() {
    cout<<":";
    int liczba=100*liczebnoscOddzialu_/liczebnoscPoczatkowa;
    if(liczba==100)
    {
        cout<<"00";
        return;
    }
    if(liczba<10)
    {
        cout<<0;
    }
    cout<<liczba;

}

void Oddzial::wycofajWsparcie(Oddzial*) {

}

void Oddzial::wycofajWsparcie(Tarczownik& wspierajacy) {
    obrona_/=wspierajacy.zmianaObrona();

}

void Oddzial::wycofajWsparcie(Bebniarz& wspierajacy) {
    morale_/=wspierajacy.zmianaMorale();
}

void Oddzial::przeliczStraty() {
    if(straty_!=0)
    {
        int straty=(int)straty_;
        straty_=0;
        morale_-=straty/liczebnoscOddzialu_;
        liczebnoscOddzialu_-=straty;
}
}



void Oddzial::ustawPole(Pole * pole) {
    pole_=pole;
}

void Oddzial::zmniejszMorale() {
    if(morale_<-1||morale_>1)
    {
        morale_*=0.75;
        return;
    }
    morale_-=0.25;
}



void Oddzial::przyjmijAtakW(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}

void Oddzial::atakuj(Konny &) {

}

void Oddzial::atakuj(Oddzial &) {

}

void Oddzial::atakuj(Zasiegowa &) {

}

void Oddzial::przesunSzeregi(PoleBitwy * poleBitwy) {
    poleBitwy->przesunSzeregi(*this);

}



