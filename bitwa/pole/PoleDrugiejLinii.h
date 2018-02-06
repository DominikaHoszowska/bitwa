//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_POLEDRUGIEJLINII_H
#define BITWA_POLEDRUGIEJLINII_H

#include "Pole.h"

class PoleDrugiejLinii: public Pole{
public:
    explicit PoleDrugiejLinii() = default;

    Oddzial* kogoWspierac(Wojsko *wojsko) override;

    void czyMogeAtakowac(Oddzial *oddzial) override;


    void przyjmijAtak(Lucznik &lucznik, double d) override;

    void przyjmijAtak(Kusznik &kusznik, double d) override;

    void przesunSzeregi(PoleBitwy *bitwy) override;
};


#endif //BITWA_POLEDRUGIEJLINII_H
