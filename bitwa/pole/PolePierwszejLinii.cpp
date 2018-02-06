//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "PolePierwszejLinii.h"
#include "../wojsko/oddzial/Headers/Oddzial.h"
#include "../wojsko/Wojsko.h"
#include "../wojsko/oddzial/Headers/Kusznik.h"

Oddzial* PolePierwszejLinii::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}

void PolePierwszejLinii::czyMogeAtakowac(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}



void PolePierwszejLinii::przyjmijAtak(Lucznik &lucznik, double d) {
    lucznik.przyjmijAtak(*this,d);
}

void PolePierwszejLinii::przyjmijAtak(Kusznik &kusznik, double obrazenia) {
    kusznik.przyjmijAtak(*this,obrazenia);
}

void PolePierwszejLinii::przesunSzeregi(PoleBitwy* poleBitwy) {
    poleBitwy->przesunSzeregi(*this);
}
