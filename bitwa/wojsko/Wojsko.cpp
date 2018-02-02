//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Wojsko.h"
#include "../Gracz.h"
#include "oddzial/Headers/Oddzial.h"

Wojsko::Wojsko(Gracz *gracz_, std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy) :
        poleBitwy_(poleBitwy),
        gracz_(gracz_)

{

    for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
        for(unsigned int nrKolumny=0;nrKolumny<wojsko.at(nrWiersza).size();nrKolumny++) {
            std::shared_ptr<Oddzial> oddzial;
            switch (wojsko.at(nrWiersza).at(nrKolumny)) {
//                case Tarczownik::OZNACZENIE:
//                    oddzial = new Tarczownik();
//                    break;
//                case Lucznik::OZNACZENIE:
//                    oddzial=new Lucznik();
//                    break;
//                case Kusznik::OZNACZENIE:
//                    oddzial=new Kusznik();
//                    break;
//                case Halabardzista::OZNACZENIE:
//                    oddzial= new Halabardzista();
//                    break;
//                case Konny::OZNACZENIE:
//                    oddzial=new Konny();
//                    break;
//                case Bebniarz::OZNACZENIE:
//                    oddzial = new Bebniarz();
//                    break;
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

std::shared_ptr<Oddzial> Wojsko::wskazKogoWspierac(Pole& pole) {
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_());
}

std::shared_ptr<Oddzial> Wojsko::wskazKogoWspierac(PolePierwszejLinii &pole) {
    if(poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1)!= nullptr) {
        return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1);
    }
    if(poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1)!= nullptr) {
        return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1);
    }
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_());


}

