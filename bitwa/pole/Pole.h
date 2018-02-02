//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_POLE_H
#define BITWA_POLE_H

#include <memory>

class PoleBitwy;

#include "../wojsko/oddzial/Oddzial.h"

class Pole {
private:
    std::shared_ptr<Oddzial> oddzial_;
    PoleBitwy* poleBitwy_;
    unsigned int nrGracza_;
    unsigned int nrWiersza_;
    unsigned int nrKolumny_;

public:

    explicit Pole(PoleBitwy *poleBitwy);
    void ustawWspolrzedne(uint8_t ,unsigned int,unsigned int);
    std::shared_ptr<Oddzial> zwrocOddzial();
    void ustawOddzial(const std::shared_ptr<Oddzial>&);
    void usunOddzial();
    virtual ~Pole() = default;

};


#endif //BITWA_POLE_H


//TODO : zmiana autora plików