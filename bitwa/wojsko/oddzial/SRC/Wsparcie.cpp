//
// Created by Dominika on 02.02.2018.
//

#include "../Headers/Wsparcie.h"
#include "../../Wojsko.h"

void Wsparcie::wspieraj() {

    auto oddzial = getWojsko()->wskazKogoWspierac(this);

    oddzial->dodajWspierajacego(this);

}

