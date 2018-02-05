#ifndef BITWA_GRA_H
#define BITWA_GRA_H

#include "Gracz.h"
#include "pole/PoleBitwy.h"


class Gra {
private:
    unsigned int liczbaTur_;
    unsigned int nrTury_ = 0;
    PoleBitwy poleBitwy_;
    unsigned int dlugoscLinii_;
    Gracz pierwszyGracz_;
    Gracz drugiGracz_;


public:

    Gra(unsigned int liczbaTur, unsigned int dlugoscLinii,const std::vector<std::vector<std::vector<char>>>& wojska);

    bool czyKoniec();

    void rozegrajTure();
    virtual ~Gra() = default;
    virtual void wypisz();
    void wypiszPrzerywnik();

    unsigned int getDlugoscLinii() const;

     Gracz &getPierwszyGracz_() ;

     Gracz &getDrugiGracz_() ;
};


#endif //BITWA_GRA_H
