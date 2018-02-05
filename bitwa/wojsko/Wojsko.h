//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_WOJSKO_H
#define BITWA_WOJSKO_H

#include <list>
#include "../pole/PoleBitwy.h"
#include "oddzial/Headers/Wsparcie.h"
#include "oddzial/Headers/Lucznik.h"

class Gracz;

class Wojsko {
private:
    PoleBitwy* poleBitwy_;
    std::list<Oddzial*> oddzialy_;
    Gracz* gracz_;
public:
    Wojsko(Gracz *gracz_,std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy);
    bool czyPuste();
    void wyslijWsparcie();
    void wykonajAtak();
    void wycofajWsparcie();
    void przeliczStraty();

    Oddzial* wskazKogoWspierac(Wsparcie* wsparcie);
    Oddzial* wskazKogoWspierac(const PolePierwszejLinii&);
    Oddzial* wskazKogoWspierac(const Pole&);
    virtual Oddzial* znajdzPrzeciwnika(Oddzial&);
    virtual Oddzial* znajdzPrzeciwnika(Lucznik&);
    void likwidacjaZmianaMorale(Pole*);
    void przesunSzeregi(Pole*);
    virtual void przesunSzeregi(PolePierwszejLinii&);
    virtual void przesunSzeregi(PoleDrugiejLinii&);
    virtual void konsoldacjaSzeregow(unsigned int);
    void zamienTarczownika(Pole*);
    void konsoldacjaSzeregowPierwszaPolowa(unsigned int);
    void konsoldacjaSzeregowDrugaPolowa(unsigned int);

};


#endif //BITWA_WOJSKO_H
