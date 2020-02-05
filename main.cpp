/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "planetsystem.h"


#define TMAX 1e4

using namespace std;

int main() {

    planetsystem system;

    system.planet1.r.x = 100;
    system.planet1.r.y = 100;
    system.planet1.v.x = 100;
    system.planet1.v.x = 100;
    system.planet1.m = 100;
    system.planet2.r.x = 100;
    system.planet2.r.y = 100;
    system.planet2.v.x = 100;
    system.planet2.v.y = 100;
    system.planet2.m = 100;

    //FILE *F = fopen("/home/vadimsam/data.txt", "w");

    for (int i = 0; i <= TMAX; i++) {
        system.planet1.move(system.planet2.m, system.planet2.r);
        system.planet2.move(system.planet2.m, system.planet2.r);


        //if (i % 10)
            //fprintf(F, "%lf %lf %lf %lf %i\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x,system.planet2.r.y, i);
	//printf("%lf %lf %lf %lf %i\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x,
                    //system.planet2.r.y, i);

        if (i % 10){
            //fprintf(F, "%lf %lf %lf %lf %i\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x,system.planet2.r.y, i);
	printf("%lf %lf %lf %lf %i\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x,
                    system.planet2.r.y, i);
        }
    }
    return 0;
}
