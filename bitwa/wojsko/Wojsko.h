//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_WOJSKO_H
#define BITWA_WOJSKO_H

#include <list>
#include "../pole/PoleBitwy.h"
#include "oddzial/Headers/Wsparcie.h"

class Gracz;

class Wojsko {
private:
    PoleBitwy* poleBitwy_;
    std::list<std::shared_ptr<Oddzial>> oddzialy_;
    Gracz* gracz_;
public:
    Wojsko(Gracz *gracz_,std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy);
    bool czyPuste();
    void wyslijWsparcie();
    void wykonajAtak();
    void wycofajWsparcie();

    Oddzial* wskazKogoWspierac(Wsparcie* wsparcie);

    std::shared_ptr<Oddzial> wskazKogoWspierac(const PolePierwszejLinii&);
    std::shared_ptr<Oddzial> wskazKogoWspierac(const Pole&);
};


#endif //BITWA_WOJSKO_H
