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

Wojsko::Wojsko(Gracz *gracz_, std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy) :
        poleBitwy_(poleBitwy),
        gracz_(gracz_)

{

    for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
        for(unsigned int nrKolumny=0;nrKolumny<wojsko.at(nrWiersza).size();nrKolumny++) {
            std::shared_ptr<Oddzial> oddzial;
            switch (wojsko.at(nrWiersza).at(nrKolumny)) {
                case Tarczownik::OZNACZENIE:
                    oddzial = std::make_shared<Tarczownik>();
                    break;
                case Lucznik::OZNACZENIE:
                    oddzial=std::make_shared<Lucznik>();
                    break;
                case Kusznik::OZNACZENIE:
                    oddzial=std::make_shared<Kusznik>();
                    break;
                case Halabardzista::OZNACZENIE:
                    oddzial= std::make_shared<Halabardzista>();
                    break;
                case Konny::OZNACZENIE:
                    oddzial=std::make_shared<Konny>();
                    break;
                case Bebniarz::OZNACZENIE:
                    oddzial = std::make_shared<Bebniarz>();
                    break;
                case 'X':
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
for(std::shared_ptr<Oddzial> oddzial:oddzialy_)
{
    oddzial->wspieraj();
}
}

void Wojsko::wykonajAtak() {
    for(std::shared_ptr<Oddzial> oddzial:oddzialy_)
    {
        oddzial->atakuj();
    }}

void Wojsko::wycofajWsparcie() {
    for(std::shared_ptr<Oddzial> oddzial:oddzialy_)
    {
        oddzial->wycofajWsparcie();
    }
}

Oddzial* Wojsko::wskazKogoWspierac(Wsparcie *wsparcie) {

     auto pole = wsparcie->getPole();

    return (pole->kogoWspierac(this)).get();

}

std::shared_ptr<Oddzial> Wojsko::wskazKogoWspierac(const Pole &pole ) {
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_())->zwrocOddzial();
}

std::shared_ptr<Oddzial> Wojsko::wskazKogoWspierac(const PolePierwszejLinii &pole) {
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



