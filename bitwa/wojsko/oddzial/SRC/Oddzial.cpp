//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "../Headers/Oddzial.h"
#include "../../Wojsko.h"

void Oddzial::wspieraj() {
}

void Oddzial::atakuj() {
    //TODO
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

