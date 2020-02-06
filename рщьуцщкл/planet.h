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

#include <cmath>
#include "customvector.h"

#define DT 0.1
const double G = 6.67408e-11;

class planet {
public:
    cvector f{},v{},r{};
    double m{};

    planet() = default;

    void move(double m2, cvector r2) {
        r = v * DT;
        f = G * m * m2 / pow(sqrt(r2 * r), 3) * r - r2;
        v = v + f * DT;
    }
};