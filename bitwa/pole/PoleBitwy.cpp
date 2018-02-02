//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "PoleBitwy.h"

PoleBitwy::PoleBitwy(unsigned int dlugoscLinii):poleGry_(2)
{
    for(int i=0;i<3;i++) {
        poleGry_.at(0).push_back(std::vector<Pole *>(0));
        poleGry_.at(1).push_back(std::vector<Pole *>(0));
    }
    for(uint8_t nrGracza=0;nrGracza<2;nrGracza++){
        for (unsigned int i = 0; i < dlugoscLinii; ++i){
            poleGry_.at(nrGracza).at(0).push_back(new PolePierwszejLinii(this));
            poleGry_.at(nrGracza).at(0).at(i)->ustawWspolrzedne(0,0,i);

            poleGry_.at(nrGracza).at(1).push_back(new PoleDrugiejLinii(this));
            poleGry_.at(nrGracza).at(1).at(i)->ustawWspolrzedne(0,1,i);

            poleGry_.at(nrGracza).at(2).push_back(new PolePosilkow(this));
            poleGry_.at(nrGracza).at(2).at(i)->ustawWspolrzedne(0,2,i);

        }
    }
}

void PoleBitwy::ustawOddzial(uint8_t nrGracza, int nrWiersza, int nrKolumny, std::shared_ptr<Oddzial> oddzial) {
    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustawOddzial(oddzial);
}
