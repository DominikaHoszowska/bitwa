//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_POLEPOSILKOW_H
#define BITWA_POLEPOSILKOW_H


#include "Pole.h"

class PolePosilkow: public Pole{
public:
    explicit PolePosilkow(PoleBitwy *poleBitwy);
    Oddzial* kogoWspierac(Wojsko *wojsko) override;

    void czyMogeAtakowac(Oddzial *oddzial) override;
};


#endif //BITWA_POLEPOSILKOW_H
