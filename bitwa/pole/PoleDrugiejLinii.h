//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_POLEDRUGIEJLINII_H
#define BITWA_POLEDRUGIEJLINII_H

#include "Pole.h"

class PoleDrugiejLinii: public Pole{
public:
    explicit PoleDrugiejLinii(PoleBitwy *poleBitwy);

    Oddzial* kogoWspierac(Wojsko *wojsko) override;

    void czyMogeAtakowac(Oddzial *oddzial) override;

    void przesunSzeregi(Wojsko *wojsko) override;

    void przyjmijAtak(Lucznik &lucznik, double d) override;
};


#endif //BITWA_POLEDRUGIEJLINII_H
