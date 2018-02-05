#ifndef BITWA_POLEBITWY_H
#define BITWA_POLEBITWY_H
#include <vector>
#include "PolePosilkow.h"
#include "PoleDrugiejLinii.h"
#include "PolePierwszejLinii.h"
#include "../wojsko/oddzial/Headers/Lucznik.h"

class Gra;

class PoleBitwy {
private:

    using wiersz_t = std::vector<Pole*>;
    using wojsko_t = std::vector<wiersz_t>;
    std::vector<wojsko_t> poleGry_;
    Gra* gra_;
public:

    explicit PoleBitwy(unsigned int dlugoscLinii);

    void ustawOddzial(uint8_t gracz, int nrWiersza, int nrKolumny, Oddzial*);

    virtual ~PoleBitwy() = default;
    Pole* zwrocPole(uint8_t gracz, int nrWiersza, int nrKolumny);
    virtual void wypisz();

    Gra* getGra() const;

    void setGra(Gra *gra);
    virtual Oddzial* znajdzPrzeciwnika(Oddzial&, uint8_t);

    virtual Oddzial* znajdzPrzeciwnika(Lucznik&, uint8_t);

};


#endif //BITWA_POLEBITWY_H
