#include "Oddzial.h"//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_ZWARCIE_H
#define BITWA_ZWARCIE_H


class Zwarcie: virtual public Oddzial{
public:
    void atakuj(PoleDrugiejLinii& linii) override;
};


#endif //BITWA_ZWARCIE_H
