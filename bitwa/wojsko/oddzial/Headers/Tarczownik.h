//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_TARCZOWNIK_H
#define BITWA_TARCZOWNIK_H


#include "Wsparcie.h"
#include "Zwarcie.h"

class Tarczownik: public Zwarcie, public Wsparcie{
public:

    using Oddzial::atakuj;

    Tarczownik();
    static const char OZNACZENIE = 'T';

    double zmianaMorale() override;
    double zmianaObrona() override;

    void atakuj() override;

    const void wypisz() override;

    void przyjmijAtak(double d) override;

    void wycofajWsparcie(Oddzial *oddzial) override;

    void przesunSzeregiT(Wojsko*) override;
};


#endif //BITWA_TARCZOWNIK_H
