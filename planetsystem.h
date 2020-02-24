#ifndef OSIM1_PLANETSYSTEM_H
#define OSIM1_PLANETSYSTEM_H

#include "planet.h"

#define G 6.67408e-11

class planetsystem {
public:
    planet *planets;
    unsigned N;

    explicit planetsystem(unsigned n) {
        planets = new planet[n];
        N = n;
    }

    ~planetsystem() {
        delete[]planets;
    }

    planetsystem(const planetsystem &A) {
        planets = new planet[A.N];
        for (int i = 0; i < A.N; i++)
            planets[i] = A.planets[i];
        N = A.N;
    }

    void move() {
        cvector f;
        for (int i = 0; i < N; i++)
            planets[i].f = cvector(0., 0.);
        for (int i = 0; i < N; i++) {
            for (int x = i + 1; x < N; x++) {
                f = ((-G * (planets[i].m * planets[x].m)) / (pow(abs(planets[i].r - planets[x].r), 3))) *
                    (planets[i].r - planets[x].r);
                planets[i].f += -f;
                planets[x].f += f;
            }
            planets[i].move();
        }
    }
};

#endif //OSIM1_PLANETSYSTEM_H
