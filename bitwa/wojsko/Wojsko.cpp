//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Wojsko.h"
#include "../Gracz.h"
#include "oddzial/Headers/Tarczownik.h"
#include "oddzial/Headers/Kusznik.h"
#include "oddzial/Headers/Halabardzista.h"
#include "oddzial/Headers/Konny.h"
#include "oddzial/Headers/Bebniarz.h"
#include "oddzial/Headers/Miecznik.h"
#include "../Gra.h"


Wojsko::Wojsko(Gracz *gracz_, std::vector<std::vector<char>> wojsko, PoleBitwy *poleBitwy) :
        poleBitwy_(poleBitwy),
        gracz_(gracz_) {
    for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
        for (unsigned int nrKolumny = 0; nrKolumny < wojsko.at(nrWiersza).size(); nrKolumny++) {
            Oddzial *oddzial = nullptr;
            switch (wojsko.at(nrWiersza).at(nrKolumny)) {
                case Tarczownik::OZNACZENIE:
                    oddzial = new Tarczownik();
                    break;
                case Lucznik::OZNACZENIE:
                    oddzial = new Lucznik();
                    break;
                case Kusznik::OZNACZENIE:
                    oddzial = new Kusznik();
                    break;
                case Halabardzista::OZNACZENIE:
                    oddzial = new Halabardzista();
                    break;
                case Konny::OZNACZENIE:
                    oddzial = new Konny();
                    break;
                case Bebniarz::OZNACZENIE:
                    oddzial = new Bebniarz();
                    break;
                case Miecznik::OZNACZENIE:
                    oddzial = new Miecznik;
                    break;
                case 'X':
                    oddzial = nullptr;
                    break;
                default:
                    throw std::invalid_argument("Nieprawidlowy znak na planszy");
            }
            if(oddzial!= nullptr) {
                oddzial->setWojsko(this);
                oddzialy_.push_back(oddzial);
            }
            poleBitwy_->ustawOddzial(gracz_->zwrocIdentyfikator(), nrWiersza, nrKolumny, oddzial);

        }
    }
}

bool Wojsko::czyPuste() {

    return (oddzialy_.empty());
}

void Wojsko::wyslijWsparcie() {
    for (Oddzial *oddzial : oddzialy_) {
        oddzial->wspieraj();
    }
}

void Wojsko::wykonajAtak() {
    for (Oddzial *oddzial:oddzialy_) {
        oddzial->atakuj();
    }
}

void Wojsko::wycofajWsparcie() {
    for (Oddzial *oddzial:oddzialy_) {
        oddzial->wycofajWsparcie();
    }
}

Oddzial *Wojsko::wskazKogoWspierac(Wsparcie *wsparcie) {


    return wsparcie->getPole()->kogoWspierac(this);

}

Oddzial *Wojsko::wskazKogoWspierac(const Pole &pole) {
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_())->zwrocOddzial();
}

Oddzial *Wojsko::wskazKogoWspierac(const PolePierwszejLinii &pole) {
    PoleBitwy *poleBitwy = poleBitwy_;
    Gra *gra = poleBitwy->getGra();
    unsigned int dlugoscLinii = gra->getDlugoscLinii();
    if (pole.getNrKolumny_() > 0) {
        if (poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1) != nullptr) {
            return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() - 1)->zwrocOddzial();
        }
    }
    if (pole.getNrKolumny_() < (dlugoscLinii - 1)) {
        if (poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1) != nullptr) {
            return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_() + 1)->zwrocOddzial();
        }
    }
    return poleBitwy_->zwrocPole(pole.getNrGracza_(), 0, pole.getNrKolumny_())->zwrocOddzial();

}

Oddzial *Wojsko::znajdzPrzeciwnika(Oddzial &oddzial) {

    uint8_t nrPrzeciwnika;
    if (this->gracz_->zwrocIdentyfikator()) {
        nrPrzeciwnika = 0;

    } else {
        nrPrzeciwnika = 1;
    }
    return this->poleBitwy_->znajdzPrzeciwnika(oddzial, nrPrzeciwnika);


}

Oddzial *Wojsko::znajdzPrzeciwnika(Lucznik &lucznik) {
    uint8_t nrPrzeciwnika;
    if (this->gracz_->zwrocIdentyfikator()) {
        nrPrzeciwnika = 0;

    } else {
        nrPrzeciwnika = 1;
    }
    return this->poleBitwy_->znajdzPrzeciwnika(lucznik, nrPrzeciwnika);
}

void Wojsko::przeliczStraty() {

    auto tempOddzialy = oddzialy_;

    for (Oddzial *oddzial: tempOddzialy) {
        oddzial->przeliczStraty();
    }
}

void Wojsko::likwidacjaZmianaMorale(Pole *pole) {
    if (pole->getNrKolumny_() > 0) {
        for (unsigned int nrWiersza = 0; nrWiersza < 2; nrWiersza++) {
            if (poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza, pole->getNrKolumny_() - 1)->zwrocOddzial() !=
                nullptr) {
                poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza,
                                      pole->getNrKolumny_() - 1)->zwrocOddzial()->zmniejszMorale();
            }
        }
    }
    for (unsigned int nrWiersza = 0; nrWiersza < 2; nrWiersza++) {
        if (poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza, pole->getNrKolumny_()) != pole &&
            poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza, pole->getNrKolumny_())->zwrocOddzial() != nullptr) {
            poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza,
                                  pole->getNrKolumny_())->zwrocOddzial()->zmniejszMorale();
        }
    }
    if (pole->getNrKolumny_() < poleBitwy_->getGra()->getDlugoscLinii() - 1) {
        for (unsigned int nrWiersza = 0; nrWiersza < 2; nrWiersza++) {
            if (poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza, pole->getNrKolumny_() + 1)->zwrocOddzial() !=
                nullptr) {
                poleBitwy_->zwrocPole(pole->getNrGracza_(), nrWiersza,
                                      pole->getNrKolumny_() + 1)->zwrocOddzial()->zmniejszMorale();
            }
        }

    }
}

void Wojsko::usunOddzial(Oddzial* oddzial) {
    oddzialy_.remove(oddzial);
    delete oddzial;
}
