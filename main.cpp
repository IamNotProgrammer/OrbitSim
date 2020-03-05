#include <iostream>
#include "planetsystem.h"

#define TMAX 1.25e7

using namespace std;

int main() {

    planetsystem system(11);

    double alpha, beta, rocketvelabs, rocketh;

    alpha = 90.;
    beta = 0.;
    rocketvelabs = 15.e3;
    rocketh = 655.e4;

    system.objects[0].r.x = 0.; //sun
    system.objects[0].r.y = 0.;
    system.objects[0].v.x = 0.;
    system.objects[0].v.y = 0.;
    system.objects[0].m = 1.989e30;

    system.objects[1].r.x = 57909227.e3; //mercury
    system.objects[1].r.y = 0.;
    system.objects[1].v.x = 0.;
    system.objects[1].v.y = 4.7362e4;
    system.objects[1].m = 330104.e18;

    system.objects[2].r.x = 108209475.e3; //venus
    system.objects[2].r.y = 0.;
    system.objects[2].v.x = 0.;
    system.objects[2].v.y = 3.5020e4;
    system.objects[2].m = 486732.e19;

    system.objects[3].r.x = 149598262.e3; //earth
    system.objects[3].r.y = 0.;
    system.objects[3].v.x = 0.;
    system.objects[3].v.y = 2.9783e4;
    system.objects[3].m = 597219.e19;

    system.objects[4].r.x = 227943824.e3; //mars
    system.objects[4].r.y = 0.;
    system.objects[4].v.x = 0.;
    system.objects[4].v.y = 2.4077e4;
    system.objects[4].m = 641693.e18;

    system.objects[5].r.x = 778340821.e3; //jupiter
    system.objects[5].r.y = 0.;
    system.objects[5].v.x = 0.;
    system.objects[5].v.y = 1.3056e4;
    system.objects[5].m = 189813.e22;

    system.objects[6].r.x = 1426666422.e3; //saturn
    system.objects[6].r.y = 0.;
    system.objects[6].v.x = 0.;
    system.objects[6].v.y = 9.6391e3;
    system.objects[6].m = 568319.e21;

    system.objects[7].r.x = 2870658186.e3; //uranus
    system.objects[7].r.y = 0.;
    system.objects[7].v.x = 0.;
    system.objects[7].v.y = 6.7991e3;
    system.objects[7].m = 868103.e20;

    system.objects[8].r.x = 4498396441.e3; //neptune
    system.objects[8].r.y = 0.;
    system.objects[8].v.x = 0.;
    system.objects[8].v.y = 5.4349e3;
    system.objects[8].m = 102410.21;

    system.objects[9].r.x = system.objects[3].r.x + 384399.e3; //earth's moon
    system.objects[9].r.y = 0.;
    system.objects[9].v.x = 0.;
    system.objects[9].v.y = system.objects[3].v.y + 1023.;
    system.objects[9].m = 7.3477e22;

    system.objects[10].r.x = system.objects[3].r.x + cos(beta / 180 * M_PI) * rocketh; //rocket
    system.objects[10].r.y = system.objects[3].r.y + sin(beta / 180 * M_PI) * rocketh;
    system.objects[10].v.x = system.objects[3].v.x + cos(alpha / 180 * M_PI) * rocketvelabs;
    system.objects[10].v.y = system.objects[3].v.y + sin(alpha / 180 * M_PI) * rocketvelabs;
    system.objects[10].m = 100.;

    FILE *epsout = fopen("/home/vadimsam/eps.txt", "w");
    FILE *mrout = fopen("/home/vadimsam/mr.txt", "w");
    //FILE *F2 = fopen("/home/vadimsam/data2.txt", "w");

    for (int i = 1; i <= TMAX; i++) {

        system.move();

        if (i % 10000 == 0) {
            for (int j = 0; j < system.N; j++)
                fprintf(epsout, "%lf %lf ", system.objects[j].r.x, system.objects[j].r.y);
            fprintf(epsout, "\n");
        }

        if (i % 100 == 0) {
            cvector moondr = system.objects[3].r - system.objects[9].r;
            cvector rocketdr = system.objects[3].r - system.objects[10].r;
            fprintf(mrout, "%lf %lf %lf %lf %lf %lf", moondr.x, moondr.y, rocketdr.x, rocketdr.y, system.objects[3].r.x, system.objects[3].r.y);
            fprintf(mrout, "\n");
        }

/*        if (i % 100 == 0) {
            cvector rocketdr = system.objects[10].r - system.objects[9].r;
            fprintf(F2, "%lf %lf ", rocketdr.x, rocketdr.y);
            fprintf(F2, "\n");
        }*/
    }

    fclose(epsout);
    fclose(mrout);
    //fclose(F2);
}

//todo Try to launch rocket to the Moon.