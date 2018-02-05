//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_KUSZNIK_H
#define BITWA_KUSZNIK_H


#include "Zasiegowa.h"

class Kusznik: public Zasiegowa {
public:
    Kusznik();
    static const char OZNACZENIE= 'k';

    void atakuj(PolePierwszejLinii linii) override;

    void atakuj(PoleDrugiejLinii linii) override;

    void przyjmijAtak(double obrazenia) override;

    const void wypisz() override;
    void przyjmijAtak(PolePierwszejLinii, double);
    void przyjmijAtak(PoleDrugiejLinii, double);
};


#endif //BITWA_KUSZNIK_H
