//
// Created by Dominika on 02.02.2018.
//

#include "PoleDrugiejLinii.h"
#include "../wojsko/Wojsko.h"
#include "Pole.h"
#include "../wojsko/oddzial/Headers/Kusznik.h"
PoleDrugiejLinii::PoleDrugiejLinii(PoleBitwy *poleBitwy) : Pole(poleBitwy) {

}

Oddzial* PoleDrugiejLinii::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}

void PoleDrugiejLinii::czyMogeAtakowac(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}

void PoleDrugiejLinii::przesunSzeregi(Wojsko *wojsko) {
    wojsko->przesunSzeregi(*this);
}

void PoleDrugiejLinii::przyjmijAtak(Lucznik &lucznik, double d) {
    lucznik.przyjmijAtak(*this,d);
}

void PoleDrugiejLinii::przyjmijAtak(Kusznik &kusznik, double d) {
    kusznik.przyjmijAtak(*this,d);
}
