//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Gracz.h"


Gracz::Gracz(const uint8_t numerGracza, std::vector<std::vector<char>> wojsko, PoleBitwy *poleBitwy):
        numerGracza_(numerGracza),
        wojsko_(this, wojsko, poleBitwy)
{
}

void Gracz::wyslijWsparcie() {
    wojsko_.wyslijWsparcie();

}

void Gracz::wykonajAtak() {
    wojsko_.wykonajAtak();
}

void Gracz::wycofajWsparcie() {
    wojsko_.wycofajWsparcie();
}

void Gracz::zakonczTure() {
    wojsko_.przeliczStraty();

}

uint8_t Gracz::zwrocIdentyfikator() {
    return numerGracza_;
}

bool Gracz::czyPuste() {
    return wojsko_.czyPuste();
}
