//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Wojsko.h"
#include "../Gracz.h"
#include "oddzial/Headers/Oddzial.h"
#include "oddzial/Headers/Tarczownik.h"
#include "oddzial/Headers/Lucznik.h"
#include "oddzial/Headers/Kusznik.h"
#include "oddzial/Headers/Halabardzista.h"
#include "oddzial/Headers/Konny.h"
#include "oddzial/Headers/Bebniarz.h"
#include "oddzial/Headers/Miecznik.h"

Wojsko::Wojsko(Gracz *gracz_, std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy) :
        poleBitwy_(poleBitwy),
        gracz_(gracz_)

{

    for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
        for(unsigned int nrKolumny=0;nrKolumny<wojsko.at(nrWiersza).size();nrKolumny++) {
            Oddzial *oddzial= nullptr;
            switch (wojsko.at(nrWiersza).at(nrKolumny)) {
                case Tarczownik::OZNACZENIE:
                    oddzial = new Tarczownik();
                    break;
                case Lucznik::OZNACZENIE:
                    oddzial=new Lucznik();
                    break;
                case Kusznik::OZNACZENIE:
                    oddzial=new Kusznik();
                    break;
                case Halabardzista::OZNACZENIE:
                    oddzial= new Halabardzista();
                    break;
                case Konny::OZNACZENIE:
                    oddzial=new Konny();
                    break;
                case Bebniarz::OZNACZENIE:
                    oddzial = new Bebniarz();
                    break;
                case Miecznik::OZNACZENIE:
                    oddzial=new Miecznik;
                    break;
                case 'X':
                    oddzial= nullptr;
                    break;
                default:
                    throw std::invalid_argument("Nieprawidlowy znak na planszy");
            }
            oddzialy_.push_back(oddzial);
            poleBitwy_->ustawOddzial(gracz_->zwrocIdentyfikator(), nrWiersza, nrKolumny, oddzial);
        }
    }

}

bool Wojsko::czyPuste() {

    return (oddzialy_.empty());
}

void Wojsko::wyslijWsparcie() {
for(Oddzial* oddzial:oddzialy_)
{
    oddzial->wspieraj();
}
}

void Wojsko::wykonajAtak() {
    for(Oddzial* oddzial:oddzialy_)
    {
        oddzial->atakuj();
    }}

void Wojsko::wycofajWsparcie() {
    for(Oddzial* oddzial:oddzialy_)
    {
        oddzial->wycofajWsparcie();
    }
}

Oddzial* Wojsko::wskazKogoWspierac(Wsparcie *wsparcie) {//TODO probelem z naruszeniem pamieci


    return   wsparcie->getPole()->kogoWspierac(this);

}

Oddzial* Wojsko::wskazKogoWspierac(const Pole &pole ) {
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_())->zwrocOddzial();
}

Oddzial* Wojsko::wskazKogoWspierac(const PolePierwszejLinii &pole) {
    if(poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1)!= nullptr) {
        return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1)->zwrocOddzial();
    }
    if(poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1)!= nullptr) {
        return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1)->zwrocOddzial();
    }
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_())->zwrocOddzial();

}

Oddzial *Wojsko::znajdzPrzeciwnika(Oddzial) {
    //TODO
    return nullptr;

}

Oddzial *Wojsko::znajdzPrzeciwnika(Lucznik) {
    //TODO

    return nullptr;
}



