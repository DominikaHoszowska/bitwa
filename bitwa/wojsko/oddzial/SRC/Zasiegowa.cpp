//
// Created by Dominika on 02.02.2018.
//

#include "../Headers/Zasiegowa.h"

void Zasiegowa::przyjmijAtakW(Oddzial *oddzial) {
    oddzial->atakuj(*this);
}
