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
    Oddzial* oddzial_;
    PoleBitwy* poleBitwy_;
    unsigned int nrGracza_;
    unsigned int nrWiersza_;
    unsigned int nrKolumny_;

public:

    explicit Pole(PoleBitwy *poleBitwy);
    void ustawWspolrzedne(uint8_t ,unsigned int,unsigned int);

     Oddzial* getOddzial() ;
    Oddzial* zwrocOddzial();
    void ustawOddzial( Oddzial*);
    void usunOddzial();
    virtual ~Pole() = 0;
    virtual Oddzial* kogoWspierac(Wojsko *wojsko);

    unsigned int getNrGracza_() const;

    unsigned int getNrWiersza_() const;

    unsigned int getNrKolumny_() const;
    virtual void czyMogeAtakowac(Oddzial*);
    const void wypisz();
    virtual void przesunSzeregi(Wojsko*);
};


#endif //BITWA_POLE_H