#ifndef BITWA_POLEBITWY_H
#define BITWA_POLEBITWY_H
#include <vector>
#include "PolePosilkow.h"
#include "PoleDrugiejLinii.h"
#include "PolePierwszejLinii.h"


class PoleBitwy {
private:

    using wiersz_t = std::vector<std::shared_ptr<Pole>>;
    using wojsko_t = std::vector<wiersz_t>;
    std::vector<wojsko_t> poleGry_;

public:

    explicit PoleBitwy(unsigned int dlugoscLinii);

    void ustawOddzial(uint8_t gracz, int nrWiersza, int nrKolumny, std::shared_ptr<Oddzial>);

    virtual ~PoleBitwy() = default;
};


#endif //BITWA_POLEBITWY_H
