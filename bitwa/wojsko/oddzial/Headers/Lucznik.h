//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_LUCZNIK_H
#define BITWA_LUCZNIK_H


#include "Zasiegowa.h"

class Lucznik: public Zasiegowa{
public:
    Lucznik();
    static const char OZNACZENIE = 'L';

    void atakuj(PolePierwszejLinii linii) override;

    void atakuj(PoleDrugiejLinii linii) override;

    void przyjmijAtak(double) override;

    const void wypisz() override;
};


#endif //BITWA_LUCZNIK_H
