//
// Created by Dominika Hoszowska on 01.02.2018.
//

#ifndef BITWA_ODDZIAL_H
#define BITWA_ODDZIAL_H


#include <list>
class Pole;
#include "../Wojsko.h"


class Oddzial {
private:

    Pole* pole_;
    Wojsko* wojsko_;
    double straty_;
    double morale_;
    std::list<Oddzial*> wsparcie_;

protected:
    int silaAtaku_;
    double obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;

};


#endif //BITWA_ODDZIAL_H
