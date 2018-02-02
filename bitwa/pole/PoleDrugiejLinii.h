//
// Created by Dominika on 02.02.2018.
//

#ifndef BITWA_POLEDRUGIEJLINII_H
#define BITWA_POLEDRUGIEJLINII_H


#include "Pole.h"

class PoleDrugiejLinii: public Pole{
public:
    explicit PoleDrugiejLinii(PoleBitwy *poleBitwy);

    std::shared_ptr<Oddzial> kogoWspierac(Wojsko *wojsko) override;
};


#endif //BITWA_POLEDRUGIEJLINII_H
