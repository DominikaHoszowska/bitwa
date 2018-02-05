//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <iostream>
#include "PoleBitwy.h"
#include "../Gra.h"
using std::cout;
PoleBitwy::PoleBitwy(unsigned int dlugoscLinii):
        poleGry_(2, wojsko_t(3))
{

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

void PoleBitwy::ustawOddzial(uint8_t nrGracza, int nrWiersza, int nrKolumny, Oddzial* oddzial) {
    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustawOddzial(oddzial);
}

Pole* PoleBitwy::zwrocPole(uint8_t nrGracza, int nrWiersza, int nrKolumny) {
    return poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny);
}

void PoleBitwy::wypisz() {
    for(unsigned int nrGracza=0;nrGracza<2;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
           cout<<"            ";
            for (unsigned int nrKolumny=0;nrKolumny<this->gra_->getDlugoscLinii();nrKolumny++)
            {

                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->wypisz();
               cout<<" ";
            }
            cout<<std::endl;
        }

        this->getGra()->wypiszPrzerywnik();
    }

}

Gra *PoleBitwy::getGra() const {
    return gra_;
}

void PoleBitwy::setGra(Gra *gra) {
    PoleBitwy::gra_ = gra;
}
