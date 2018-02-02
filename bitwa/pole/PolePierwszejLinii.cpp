//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "PolePierwszejLinii.h"
#include "../wojsko/oddzial/Headers/Oddzial.h"
#include "../wojsko/Wojsko.h"
PolePierwszejLinii::PolePierwszejLinii(PoleBitwy *poleBitwy) : Pole(poleBitwy) {

}

std::shared_ptr<Oddzial> PolePierwszejLinii::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}
