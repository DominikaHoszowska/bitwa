//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_BEBNIARZ_H
#define BITWA_BEBNIARZ_H


#include "Zasiegowa.h"
#include "Wsparcie.h"
class Bebniarz: public Zasiegowa, public Wsparcie {
public:
    double zmianaMorale() override;

    double zmianaObrona() override;
};


#endif //BITWA_BEBNIARZ_H
