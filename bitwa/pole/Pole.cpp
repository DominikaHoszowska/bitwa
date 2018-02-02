//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Pole.h"

Pole::Pole(PoleBitwy *poleBitwy): poleBitwy_(poleBitwy) {

}

std::shared_ptr<Oddzial> Pole::zwrocOddzial() {
    return oddzial_;
}

void Pole::ustawOddzial(const std::shared_ptr<Oddzial>& oddzial) {
    oddzial_= oddzial;
}

void Pole::usunOddzial() {
    oddzial_.reset();
}

void Pole::ustawWspolrzedne(uint8_t nrGracza, unsigned int nrWiersza, unsigned int nrKolumny) {
    nrGracza_=nrGracza;
    nrWiersza_=nrWiersza;
    nrKolumny_=nrKolumny;

}


Pole::~Pole() {

}

