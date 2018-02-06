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

    void ustawOddzial(int gracz, int nrWiersza, int nrKolumny, Oddzial*);

    virtual ~PoleBitwy() = default;
    Pole* zwrocPole(int gracz, int nrWiersza, int nrKolumny);
    virtual void wypisz();

    Gra* getGra() const;

    void setGra(Gra *gra);
    virtual Oddzial* znajdzPrzeciwnika(Oddzial&, int);

    virtual Oddzial* znajdzPrzeciwnika(Lucznik&, int);
    void zmianaMorale();
    void usunPoleglych();
    void usunPoleglych1(int);
    void usunPoleglych2(int);
    void przesunSzeregi(Pole*);
    virtual void przesunSzeregi(PolePierwszejLinii&);
    virtual void przesunSzeregi(PoleDrugiejLinii&);
    void konsolidacja(unsigned int);
    virtual void przesunSzeregi(Oddzial&);
    virtual void przesunSzeregi(Tarczownik&);
    void konsolidacja1(Pole*);
    void konsolidacja2(Pole*);


};


#endif //BITWA_POLEBITWY_H
