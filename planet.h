#ifndef OSIM1_PLANET_H
#define OSIM1_PLANET_H

#include "cvector.h"

#define  DT 1

class planet {
public:
    double m{};
    cvector r, v, f;

    planet() = default;

    void move() {
        r = r + v * DT;
        v = v + f / m * DT;
    }
};

#endif //OSIM1_PLANET_H
