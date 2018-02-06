//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <iostream>
#include "Pole.h"
#include "../wojsko/oddzial/Headers/Oddzial.h"
#include "../wojsko/Wojsko.h"

void Pole::ustawOddzial ( Oddzial* oddzial) {
    oddzial_= oddzial;
    if(oddzial!= nullptr)
    oddzial->ustawPole(this);
}

void Pole::usunOddzial() {
    delete oddzial_;
}

void Pole::ustawWspolrzedne(uint8_t nrGracza, unsigned int nrWiersza, unsigned int nrKolumny) {
    nrGracza_=nrGracza;
    nrWiersza_=nrWiersza;
    nrKolumny_=nrKolumny;

}


Pole::~Pole() {

}

 Oddzial* Pole::getOddzial()  {
    return oddzial_;
}

unsigned int Pole::getNrGracza_() const {
    return nrGracza_;
}

unsigned int Pole::getNrWiersza_() const {
    return nrWiersza_;
}

unsigned int Pole::getNrKolumny_() const {
    return nrKolumny_;
}
Oddzial* Pole::zwrocOddzial() {
    return oddzial_;
}

void Pole::czyMogeAtakowac(Oddzial *) {

}

const void Pole::wypisz() {
    if(getOddzial()!= nullptr)
        getOddzial()->wypisz();
    else
    {
        std::cout<<" X ";
    }
}

Oddzial *Pole::kogoWspierac(Wojsko *wojsko) {
    return nullptr;
}



void Pole::przyjmijAtak(Lucznik&, double) {
//nie robimy nic
}

void Pole::przyjmijAtak(Kusznik &, double) {
//nie robimy nic
}

void Pole::przesunSzeregi(PoleBitwy*) {
//nic nie robimy
}



