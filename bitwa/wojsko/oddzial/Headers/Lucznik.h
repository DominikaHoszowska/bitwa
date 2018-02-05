//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_LUCZNIK_H
#define BITWA_LUCZNIK_H


#include "Zasiegowa.h"

class Lucznik: public Zasiegowa{
public:

    using Oddzial::atakuj;

    Lucznik();
    static const char OZNACZENIE = 'L';

    void atakuj(PolePierwszejLinii&) override;

    void atakuj(PoleDrugiejLinii& ) override;

    void przyjmijAtak(double) override;

    const void wypisz() override;
    void przyjmijAtak(PolePierwszejLinii&, double);
    void przyjmijAtak(PoleDrugiejLinii&, double);
};


#endif //BITWA_LUCZNIK_H
