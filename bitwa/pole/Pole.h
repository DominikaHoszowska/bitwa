//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_POLE_H
#define BITWA_POLE_H

#include <memory>

class Wojsko;
class PoleBitwy;
class Oddzial;

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

    const std::shared_ptr<Oddzial> &getOddzial() const;
    std::shared_ptr<Oddzial> zwrocOddzial();
    void ustawOddzial(const std::shared_ptr<Oddzial>&);
    void usunOddzial();
    virtual ~Pole() = 0;
    virtual std::shared_ptr<Oddzial> kogoWspierac(Wojsko *wojsko)=0;


    unsigned int getNrGracza_() const;

    unsigned int getNrWiersza_() const;

    unsigned int getNrKolumny_() const;
    virtual void czyMogeAtakowac(Oddzial*);
};


#endif //BITWA_POLE_H


//TODO : zmiana autora plików