//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_POLEPIERSZEJLINII_H
#define BITWA_POLEPIERSZEJLINII_H

#include "Pole.h"

class PolePierwszejLinii
        : public Pole {
public:
    explicit PolePierwszejLinii(PoleBitwy *poleBitwy);

    Oddzial* kogoWspierac(Wojsko *wojsko) override;

    void czyMogeAtakowac(Oddzial *oddzial) override;

    void przesunSzeregi(Wojsko *wojsko) override;
};


#endif //BITWA_POLEPIERSZEJLINII_H
