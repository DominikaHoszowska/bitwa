//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_MIECZNIK_H
#define BITWA_MIECZNIK_H


#include "Zwarcie.h"

class Miecznik: public Zwarcie {
public:
    Miecznik();
    static const char OZNACZENIE = 'M';

    void atakuj(PolePierwszejLinii linii) override;
};


#endif //BITWA_MIECZNIK_H
