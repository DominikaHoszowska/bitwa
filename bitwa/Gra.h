#ifndef BITWA_GRA_H
#define BITWA_GRA_H

#include "Gracz.h"
#include "pole/PoleBitwy.h"


class Gra {
private:
    unsigned int liczbaTur_;
    unsigned int numerTury_ = 0;

    PoleBitwy poleBitwy_;

    Gracz pierwszyGracz_;
    Gracz drugiGracz_;


public:

    Gra(unsigned int liczbaTur, unsigned int dlugoscLinii,const std::vector<std::vector<std::vector<char>>>& wojska);

    bool czyKoniec();

    void rozegrajTure();

    virtual ~Gra() = default;


};


#endif //BITWA_GRA_H
