//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "../Headers/Oddzial.h"
#include "../../Wojsko.h"

void Oddzial::wspieraj() {
}



void Oddzial::wycofajWsparcie() {

//TODO
}

Pole *Oddzial::getPole() const {
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

int Oddzial::getZasieg_() const {
    return zasieg_;
}

void Oddzial::setZasieg_(int zasieg_) {
    Oddzial::zasieg_ = zasieg_;
}

Oddzial::Oddzial(){
    morale_=0;
}

void Oddzial::atakuj() {
    getPole()->czyMogeAtakowac(this);
}

void Oddzial::atakuj(PolePierwszejLinii) {

}

void Oddzial::atakuj(PoleDrugiejLinii) {

}

