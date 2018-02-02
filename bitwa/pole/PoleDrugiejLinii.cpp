//
// Created by Dominika on 02.02.2018.
//

#include "PoleDrugiejLinii.h"
#include "../wojsko/Wojsko.h"

PoleDrugiejLinii::PoleDrugiejLinii(PoleBitwy *poleBitwy) : Pole(poleBitwy) {

}

std::shared_ptr<Oddzial> PoleDrugiejLinii::kogoWspierac(Wojsko *wojsko) {
    wojsko->wskazKogoWspierac(static_cast<Pole>(*this));
}
