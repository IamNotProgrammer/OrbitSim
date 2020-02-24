#include <iostream>
#include "planetsystem.h"

#define TMAX 1e9
#define DT 1

using namespace std;

int main() {

    planetsystem system(2);

    system.planets[1].r.x = 149e9;
    system.planets[1].r.y = 0;
    system.planets[1].v.x = 0;
    system.planets[1].v.y = 29783.;
    system.planets[1].m = 5.9726e24;

    system.planets[0].r.x = 0.;
    system.planets[0].r.y = 0.;
    system.planets[0].v.x = 0.;
    system.planets[0].m = 1.989e30;
    system.planets[0].v.y = -(system.planets[1].m * system.planets[1].v.y) / system.planets[0].m;

    FILE *F = fopen("/home/vadimsam/data.txt", "w");

    for (int i = 1; i <= TMAX; i++) {
        system.move();
        if (i % 10000 == 0)
            fprintf(F, "%lf %lf %lf %lf\n", system.planets[0].r.x, system.planets[0].r.y, system.planets[1].r.x,
                    system.planets[1].r.y);
    }
    fclose(F);
}