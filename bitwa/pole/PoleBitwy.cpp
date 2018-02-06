//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <iostream>
#include "PoleBitwy.h"
#include "../Gra.h"
#include "../wojsko/Wojsko.h"
using std::cout;
PoleBitwy::PoleBitwy(unsigned int dlugoscLinii):
        poleGry_(2, wojsko_t(3))
{

    for(uint8_t nrGracza=0;nrGracza<2;nrGracza++){
        for (unsigned int i = 0; i < dlugoscLinii; ++i){

            poleGry_.at(nrGracza).at(0).push_back(new PolePierwszejLinii());
            poleGry_.at(nrGracza).at(0).at(i)->ustawWspolrzedne(0,0,i);

            poleGry_.at(nrGracza).at(1).push_back(new PoleDrugiejLinii());
            poleGry_.at(nrGracza).at(1).at(i)->ustawWspolrzedne(0,1,i);

            poleGry_.at(nrGracza).at(2).push_back(new PolePosilkow());
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

        for( int nrWiersza=2;nrWiersza>=0;nrWiersza--)
        {
           cout<<"            ";
            for (unsigned int nrKolumny=0;nrKolumny<this->gra_->getDlugoscLinii();nrKolumny++)
            {

                    poleGry_.at(0).at(nrWiersza).at(nrKolumny)->wypisz();
               cout<<" ";
            }
            cout<<std::endl;
        }
        this->getGra()->wypiszPrzerywnik();
        for(unsigned int nrWiersza=0;nrWiersza<=2;nrWiersza++)
    {
        cout<<"            ";
        for (unsigned int nrKolumny=0;nrKolumny<this->gra_->getDlugoscLinii();nrKolumny++)
        {

            poleGry_.at(1).at(nrWiersza).at(nrKolumny)->wypisz();
            cout<<" ";
        }
        cout<<std::endl;
    }
}

Gra *PoleBitwy::getGra() const {
    return gra_;
}

void PoleBitwy::setGra(Gra *gra) {
    PoleBitwy::gra_ = gra;
}

Oddzial *PoleBitwy::znajdzPrzeciwnika(Oddzial& atakujacy, uint8_t nrPrzeciwnika) {
    unsigned int nrKolumny=atakujacy.getPole()->getNrKolumny_();
    if(poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny)->zwrocOddzial();
    }
    unsigned int zasieg=atakujacy.getZasieg_();
    unsigned int odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(static_cast<int>(nrKolumny) - static_cast<int>(odleglosc) >= 0
           && poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<getGra()->getDlugoscLinii()&& poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    return nullptr;
}

Oddzial *PoleBitwy::znajdzPrzeciwnika(Lucznik& atakujacy, uint8_t nrPrzeciwnika ) {
    unsigned int nrKolumny=atakujacy.getPole()->getNrKolumny_();
    if(poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny)->zwrocOddzial();
    }
    unsigned int zasieg=atakujacy.getZasieg_();
    unsigned int odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(static_cast<int>(nrKolumny) - static_cast<int> (odleglosc) >= 0
           && poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<getGra()->getDlugoscLinii()&& poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(1).at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    if(poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny)->zwrocOddzial();
    }
    odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(static_cast<int>(nrKolumny) - static_cast<int>(odleglosc) >= 0
           && poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<getGra()->getDlugoscLinii()&& poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return poleGry_.at(nrPrzeciwnika).at(0).at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    return nullptr;

}

void PoleBitwy::zmianaMorale() {

    for(unsigned int nrGracza=0;nrGracza<2;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<2;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<getGra()->getDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr
                   && poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->getStraty()>
                                                 poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_())
                {
                    if(nrGracza==0)
                    {
                        getGra()->getPierwszyGracz_().getWojsko_().likwidacjaZmianaMorale(zwrocPole(nrGracza,nrWiersza,nrKolumny));
                    }
                    else
                    {
                        getGra()->getDrugiGracz_().getWojsko_().likwidacjaZmianaMorale(zwrocPole(nrGracza,nrWiersza,nrKolumny));

                    }
                }

            }
        }
    }
}

void PoleBitwy::usunPoleglych() {
    usunPoleglych1(0);
    usunPoleglych2(0);
    usunPoleglych1(1);
    usunPoleglych2(1);
}

void PoleBitwy::usunPoleglych1(int nrGracza) {

    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2)-1;nrKolumny>=0;nrKolumny--) {
        if (zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
//            zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getWojsko()
//                    ->przesunSzeregi(zwrocPole(nrGracza, 0, nrKolumny));
        }
    }
    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2)-1;nrKolumny>0;nrKolumny--) {
        if (zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
//            zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getWojsko()
//                    ->przesunSzeregi(zwrocPole(nrGracza, 0, nrKolumny));
        }
    }
}

void PoleBitwy::usunPoleglych2(int nrGracza) {
    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2);nrKolumny<getGra()->getDlugoscLinii();nrKolumny++)
    {
        if (zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
//            zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getWojsko()
//                    ->przesunSzeregi(zwrocPole(nrGracza, 0, nrKolumny));
        }

    }
    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2);nrKolumny<getGra()->getDlugoscLinii();nrKolumny++)
    {
        if (zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
//            zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getWojsko()
//                    ->przesunSzeregi(zwrocPole(nrGracza, 0, nrKolumny));
        }

    }

}
