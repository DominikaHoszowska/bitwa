//
// Created by Dominika on 02.02.2018.
//

#include "PolePosilkow.h"
#include "../wojsko/Wojsko.h"


Oddzial* PolePosilkow::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}

void PolePosilkow::czyMogeAtakowac(Oddzial *oddzial) {
    //z pola posilkow nie atakujemy
}
