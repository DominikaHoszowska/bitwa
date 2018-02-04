//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_KONNY_H
#define BITWA_KONNY_H


#include "Zwarcie.h"

class Konny: public Zwarcie{
public:
    Konny();
    static const char OZNACZENIE= 'K';

    void atakuj(PolePierwszejLinii linii) override;

    void przyjmijAtak(double d) override;

    void wypisz() override;
};


#endif //BITWA_KONNY_H
