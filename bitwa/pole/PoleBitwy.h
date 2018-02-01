#ifndef BITWA_POLEBITWY_H
#define BITWA_POLEBITWY_H


#include <vector>
#include "PolePierwszejLinii.h"

class PoleBitwy {
private:

    struct pole_gracza_t {

        pole_gracza_t(unsigned int dlugoscLinii):
                pierwszaLinia_(dlugoscLinii),
                drugaLinia_(dlugoscLinii),
                posilki_(dlugoscLinii)
                {}

        std::vector<PolePierwszejLinii> pierwszaLinia_;
        std::vector<PoleDrugiejLinii> drugaLinia_;
        std::vector<PolePosilkow> posilki_;
    };

    std::vector<pole_gracza_t> pole_;

public:

    PoleBitwy(unsigned int dlugoscLinii);

    virtual ~PoleBitwy() = default;
};


#endif //BITWA_POLEBITWY_H
