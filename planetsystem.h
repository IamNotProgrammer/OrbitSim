#ifndef OSIM1_PLANETSYSTEM_H
#define OSIM1_PLANETSYSTEM_H

double G = 6.67408e-11;

#include "object.h"

class planetsystem {
public:
    object *objects;
    unsigned N;

    explicit planetsystem(unsigned n) {
        objects = new object[n];
        N = n;
    }

    ~planetsystem() {
        delete[]objects;
    }

    planetsystem(const planetsystem &ps) {
        N = ps.N;
        objects = new object[ps.N];
        for (int i = 0; i < ps.N; i++)
            objects[i] = ps.objects[i];
    }

    void move() {
        cvector f;
        for (int i = 0; i < N; i++)
            objects[i].f = cvector(0., 0.);
        for (int i = 0; i < N; i++) {
            for (int x = i + 1; x < N; x++) {
                f = ((-G * (objects[i].m * objects[x].m)) / (pow(abs(objects[i].r - objects[x].r), 3))) *
                    (objects[i].r - objects[x].r);
                objects[i].f += -f;
                objects[x].f += f;
            }
            objects[i].move();
        }

    }

};

#endif //OSIM1_PLANETSYSTEM_H
