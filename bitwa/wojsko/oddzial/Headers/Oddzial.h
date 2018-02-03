//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_ODDZIAL_H
#define BITWA_ODDZIAL_H


#include <list>
class Pole;
class Wojsko;
class Wsparcie;


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
    int zasieg_;

public:
    virtual void wspieraj();
    virtual void atakuj()=0;
    virtual void wycofajWsparcie();

    Pole *getPole() const;
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

    int getZasieg_() const;

    void setZasieg_(int zasieg_);

    void dodajWspierajacego(Wsparcie* wsparcie);
};


#endif //BITWA_ODDZIAL_H
