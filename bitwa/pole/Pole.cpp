//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Pole.h"
#include "../wojsko/oddzial/Headers/Oddzial.h"
#include "../wojsko/Wojsko.h"


Pole::Pole(PoleBitwy *poleBitwy): poleBitwy_(poleBitwy) {

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

const std::shared_ptr<Oddzial> &Pole::getOddzial() const {
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

std::shared_ptr<Oddzial> Pole::zwrocOddzial() {
    return oddzial_;
}

