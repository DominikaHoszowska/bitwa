//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_HALABARDZISTA_H
#define BITWA_HALABARDZISTA_H


#include "Zwarcie.h"

class Halabardzista: public Zwarcie {
public:
    Halabardzista();
    static const char OZNACZENIE = 'H';

    void atakuj() override;
};


#endif //BITWA_HALABARDZISTA_H
