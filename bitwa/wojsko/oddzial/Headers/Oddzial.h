//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_ODDZIAL_H
#define BITWA_ODDZIAL_H


#include <list>
#include "../../../pole/PolePierwszejLinii.h"
#include "../../../pole/PoleDrugiejLinii.h"


class Pole;
class Wojsko;
class Wsparcie;
class Tarczownik;
class Bebniarz;
class Konny;
class Zasiegowa;

class Oddzial {
public:
    Oddzial();

private:
    Pole* pole_;
    Wojsko* wojsko_;
    double straty_;
    double morale_;
    std::list<Wsparcie*> wsparcie_;

protected:
    int silaAtaku_;
    double obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    unsigned int zasieg_;

public:
    virtual void wspieraj();
    virtual void atakuj();
    virtual void wycofajWsparcie();
    virtual void przyjmijAtak(double);

    Pole *getPole() ;
    void setPole(Pole *pole_);

    Wojsko *getWojsko() const;
    void setWojsko(Wojsko *wojsko_);

    double getStraty() const;
    void setStraty(double straty_);

    double getMorale() const;
    void setMorale(double morale_);

    int getSilaAtaku_() const;

    void setSilaAtaku_(int silaAtaku_);

    double getObrona_() const;

    void setObrona_(double obrona_);

    int getWytrzymalosc_() const;

    void setWytrzymalosc_(int wytrzymalosc_);

    int getLiczebnoscOddzialu_() const;

    void setLiczebnoscOddzialu_(int liczebnoscOddzialu_);

    int getLiczebnoscPoczatkowa() const;

    void setLiczebnoscPoczatkowa(int liczebnoscPoczatkowa);

    unsigned int getZasieg_() const;


    void dodajWspierajacego(Wsparcie* wsparcie);
    virtual void atakuj(PolePierwszejLinii&);
    virtual void atakuj(PoleDrugiejLinii&);
    virtual const void wypisz();
    void wypiszLiczebnosc();
    virtual ~Oddzial()= default;
    virtual void wycofajWsparcie(Oddzial*);
    virtual void wycofajWsparcie(Tarczownik&);
    virtual void wycofajWsparcie(Bebniarz&);
    void przeliczStraty();
    void likwidacja();
    void ustawPole(Pole*);
    void zmniejszMorale();
    virtual void przesunSzeregiT(Wojsko*);
    virtual void przyjmijAtakW(Oddzial*);

    virtual void atakuj(Konny&);
    virtual void atakuj(Oddzial&);
    virtual void atakuj(Zasiegowa&);


};


#endif //BITWA_ODDZIAL_H
