//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_POLE_H
#define BITWA_POLE_H

#include <memory>
#include "PoleBitwy.h"
#include "../wojsko/oddzial/Oddzial.h"

class Pole {
private:
    std::shared_ptr<Oddzial> oddzial_;
    PoleBitwy& poleBitwy_;
public:

    Pole(PoleBitwy& poleBitwy);

    std::shared_ptr<Oddzial> zwrodOddzial();

};


#endif //BITWA_POLE_H


//TODO : zmiana autora plików