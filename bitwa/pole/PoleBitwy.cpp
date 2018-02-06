//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include <iostream>
#include "PoleBitwy.h"
#include "../Gra.h"
#include "../wojsko/Wojsko.h"
#include "../wojsko/oddzial/Headers/Tarczownik.h"
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

    for(  int nrKolumny=(int)(getGra()->getDlugoscLinii()/2)-1;nrKolumny>=0; nrKolumny--) {
        if (zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
            zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getWojsko()
                    ->usunOddzial(zwrocPole(nrGracza, 0, nrKolumny)->getOddzial());
            poleGry_.at(nrGracza).at(0).at(nrKolumny)->ustawOddzial(nullptr);

            przesunSzeregi( poleGry_.at(nrGracza).at(0).at(nrKolumny));

        }

    }
    for( int nrKolumny=(int)(getGra()->getDlugoscLinii()/2)-1;nrKolumny>0;nrKolumny--) {
        if (zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
            przesunSzeregi(zwrocPole(nrGracza, 1, nrKolumny));
        }
    }
}

void PoleBitwy::usunPoleglych2(int nrGracza) {
    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2);nrKolumny<getGra()->getDlugoscLinii();nrKolumny++)
    {
        if (zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
            zwrocPole(nrGracza, 0, nrKolumny)->zwrocOddzial()->getWojsko()
                    ->usunOddzial(zwrocPole(nrGracza, 0, nrKolumny)->getOddzial());
            poleGry_.at(nrGracza).at(0).at(nrKolumny)->ustawOddzial(nullptr);

            przesunSzeregi( poleGry_.at(nrGracza).at(0).at(nrKolumny));

        }

    }
    for(unsigned int nrKolumny=(getGra()->getDlugoscLinii()/2);nrKolumny<getGra()->getDlugoscLinii();nrKolumny++)
    {
        if (zwrocPole(nrGracza, 1, nrKolumny)->zwrocOddzial()->getLiczebnoscOddzialu_() < 1)

        {
            przesunSzeregi(zwrocPole(nrGracza, 1, nrKolumny));
        }

    }

}

void PoleBitwy::przesunSzeregi(Pole *pole) {

    pole->przesunSzeregi(this);

}

void PoleBitwy::przesunSzeregi(PolePierwszejLinii &pole) {
    if(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())
               ->getOddzial()->getLiczebnoscOddzialu_()<1)
    {
        poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())->getOddzial()->getWojsko()
                ->usunOddzial(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())->getOddzial());
        poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())= nullptr;
        przesunSzeregi(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_()));
    }
    if(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())->getOddzial()!= nullptr)
    {
        pole.ustawOddzial(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())->getOddzial());
        poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_())->ustawOddzial(nullptr);
        przesunSzeregi(poleGry_.at(pole.getNrGracza_()).at(1).at(pole.getNrKolumny_()));
    }

}

void PoleBitwy::przesunSzeregi(PoleDrugiejLinii &pole) {
    if(poleGry_.at(pole.getNrGracza_()).at(2).at(pole.getNrKolumny_())->getOddzial()!= nullptr)
    {
        poleGry_.at(pole.getNrGracza_()).at(2).at(pole.getNrKolumny_())->getOddzial()->przesunSzeregi(this);
    }

}

void PoleBitwy::konsolidacja(unsigned int nrGracza) {

    for(int nrKolumny=(int)(getGra()->getDlugoscLinii()/2)-1;nrKolumny>0;nrKolumny--)
    {
        if(poleGry_.at(nrGracza).at(0).at(nrKolumny)->zwrocOddzial()== nullptr)
            konsolidacja1(poleGry_.at(nrGracza).at(0).at(nrKolumny));
    }
    for(int nrKolumny=(getGra()->getDlugoscLinii()/2);nrKolumny<(int)getGra()->getDlugoscLinii()-1;nrKolumny++)
    {
        if(poleGry_.at(nrGracza).at(0).at(nrKolumny)->zwrocOddzial()== nullptr)
            konsolidacja2(poleGry_.at(nrGracza).at(0).at(nrKolumny));
    }
}

void PoleBitwy::przesunSzeregi(Oddzial & oddzial) {
    Pole* pole=oddzial.getPole();
    poleGry_.at(pole->getNrGracza_()).at(1).at(pole->getNrKolumny_())->ustawOddzial(&oddzial);
    pole->ustawOddzial(nullptr);

}

void PoleBitwy::przesunSzeregi(Tarczownik& oddzial) {

    Pole* pole=oddzial.getPole();

    poleGry_.at(pole->getNrGracza_()).at(1).at(pole->getNrKolumny_())
            ->ustawOddzial(poleGry_.at(pole->getNrGracza_()).at(0).at(pole->getNrKolumny_())->getOddzial());
    poleGry_.at(pole->getNrGracza_()).at(0).at(pole->getNrKolumny_())->ustawOddzial(&oddzial);
    pole->ustawOddzial(nullptr);

}
void PoleBitwy::konsolidacja1(Pole *pole) {
    unsigned int nrGracza=pole->getNrGracza_();
    unsigned int nrKolumny=pole->getNrKolumny_();
    if(nrKolumny>0){
        for(unsigned int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
            poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustawOddzial(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny-1)->zwrocOddzial());
            poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny-1)->ustawOddzial(nullptr);
        }
        konsolidacja1(poleGry_.at(nrGracza).at(0).at(nrKolumny-1));
    }
}
void PoleBitwy::konsolidacja2(Pole *pole) {
    unsigned int nrGracza=pole->getNrGracza_();
    unsigned int nrKolumny=pole->getNrKolumny_();
    if(nrKolumny<getGra()->getDlugoscLinii()-1){
        for(unsigned int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
            poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustawOddzial(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny+1)->zwrocOddzial());
            poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny+1)->ustawOddzial(nullptr);
        }
        konsolidacja1(poleGry_.at(nrGracza).at(0).at(nrKolumny+1));
    }}
