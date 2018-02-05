//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "PolePierwszejLinii.h"
#include "../wojsko/oddzial/Headers/Oddzial.h"
#include "../wojsko/Wojsko.h"

PolePierwszejLinii::PolePierwszejLinii(PoleBitwy *poleBitwy) : Pole(poleBitwy) {

}

Oddzial* PolePierwszejLinii::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}

void PolePierwszejLinii::czyMogeAtakowac(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}

void PolePierwszejLinii::przesunSzeregi(Wojsko *wojsko) {
    wojsko->przesunSzeregi(*this);
}

void PolePierwszejLinii::przyjmijAtak(Lucznik &lucznik, double d) {
    lucznik.przyjmijAtak(*this,d);
}
