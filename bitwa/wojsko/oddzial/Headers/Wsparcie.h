//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_WSPARCIE_H
#define BITWA_WSPARCIE_H

#include "Oddzial.h"

class Wsparcie: virtual public Oddzial{
public:
    void wspieraj() override;
    virtual double zmianaMorale()=0;
    virtual double zmianaObrona()=0;

};


#endif //BITWA_WSPARCIE_H
