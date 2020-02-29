#ifndef OSIM1_OBJECT_H
#define OSIM1_OBJECT_H

#include "cvector.h"

#define  DT 1

class object {
public:
    double m{};
    cvector r, v, f;

    object() = default;

    void move() {
        r = r + v * DT;
        v = v + f / m * DT;
    }
};


#endif //OSIM1_OBJECT_H
