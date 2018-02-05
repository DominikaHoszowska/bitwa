//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_ZASIEGOWA_H
#define BITWA_ZASIEGOWA_H


#include "Oddzial.h"

class Zasiegowa: virtual public Oddzial{
public:
    void przyjmijAtakW(Oddzial *oddzial) override;
};


#endif //BITWA_ZASIEGOWA_H
