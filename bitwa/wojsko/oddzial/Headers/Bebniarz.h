//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_BEBNIARZ_H
#define BITWA_BEBNIARZ_H


#include "Zasiegowa.h"
#include "Wsparcie.h"
class Bebniarz: public Zasiegowa, public Wsparcie {
public:

    using Oddzial::atakuj;

    Bebniarz();
    static const char OZNACZENIE ='B';
    double zmianaMorale() override;
    double zmianaObrona() override;

    void atakuj() override;

    void przyjmijAtak(double d) override;

    const void wypisz() override;

    void wycofajWsparcie(Oddzial *oddzial) override;
};


#endif //BITWA_BEBNIARZ_H
