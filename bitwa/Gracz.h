//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_GRACZ_H
#define BITWA_GRACZ_H

#include <cstdint>
#include <vector>

#include "pole/Pole.h"
#include "wojsko/Wojsko.h"

class Gracz {
private:
    const uint8_t  numerGracza_;
    Wojsko wojsko_;

public:

    Gracz(uint8_t numerGracza, std::vector<std::vector<char>> wojsko, PoleBitwy& poleBitwy);


    void wyslijWsparcie();
    void wykonajAtak();
    void wycofajWsparcie();
    void zakonczTure();


    ~Gracz() = default;
};


#endif //BITWA_GRACZ_H
