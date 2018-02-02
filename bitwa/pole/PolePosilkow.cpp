//
// Created by Dominika on 02.02.2018.
//

#include "PolePosilkow.h"
#include "../wojsko/Wojsko.h"

PolePosilkow::PolePosilkow(PoleBitwy *poleBitwy) : Pole(poleBitwy) {

}

std::shared_ptr<Oddzial> PolePosilkow::kogoWspierac(Wojsko *wojsko) {
    return wojsko->wskazKogoWspierac(*this);
}
