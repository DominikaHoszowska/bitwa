//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_MIECZNIK_H
#define BITWA_MIECZNIK_H


#include "Zwarcie.h"

class Miecznik: public Zwarcie {
public:

    using Oddzial::atakuj;

    Miecznik();
    static const char OZNACZENIE = 'M';

    void atakuj(PolePierwszejLinii& linii) override;

    void przyjmijAtak(double) override;

    const void wypisz() override;
};


#endif //BITWA_MIECZNIK_H
