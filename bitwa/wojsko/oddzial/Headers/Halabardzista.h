//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_HALABARDZISTA_H
#define BITWA_HALABARDZISTA_H


#include "Zwarcie.h"

class Halabardzista: public Zwarcie {
public:

    using Oddzial::atakuj;

    Halabardzista();
    static const char OZNACZENIE = 'H';
    void atakuj(PolePierwszejLinii& linii) override;
    const void wypisz() override;

    void atakuj(Konny &konny) override;

    void atakuj(Oddzial &oddzial) override;
};


#endif //BITWA_HALABARDZISTA_H
