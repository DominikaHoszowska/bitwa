//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Gracz.h"


Gracz::Gracz(const uint8_t numerGracza, std::vector<std::vector<char>> wojsko, PoleBitwy *poleBitwy):
        numerGracza_(numerGracza),
        wojsko_(this, wojsko, poleBitwy)
{
    //TODO
}

void Gracz::wyslijWsparcie() {
    //TODO
}

void Gracz::wykonajAtak() {
    //TODO
}

void Gracz::wycofajWsparcie() {
    //TODO
}

void Gracz::zakonczTure() {
    //TODO
}

uint8_t Gracz::zwrocIdentyfikator() {
    return numerGracza_;
}

bool Gracz::czyPuste() {
    return wojsko_.czyPuste();
}
