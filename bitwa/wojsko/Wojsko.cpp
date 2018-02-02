//
// Created by Dominika Hoszowska on 01.02.2018.
//

#include "Wojsko.h"
#include "../Gracz.h"

Wojsko::Wojsko(Gracz *gracz_, std::vector<std::vector<char>> wojsko, PoleBitwy* poleBitwy) :
        gracz_(gracz_),
        poleBitwy_(poleBitwy)
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
