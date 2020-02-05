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

class cvector {
public:

    double x{};
    double y{};

    cvector() = default;

    double abs() {
       return hypot(x, y);
    }

    cvector operator +(const cvector& b)const {
        cvector res;
        res.x = b.x + x;
        res.y = b.y + y;
        return res;
    }
    cvector operator -(const cvector& b)const {
        cvector res;
        res.x = b.x - x;
        res.y = b.y - y;
        return res;
    }
    cvector operator *(const cvector& b)const {
        cvector res;
        res.x = b.x * x;
        res.y = b.y * y;
        return res;
    }
    cvector operator /(const cvector& b)const {
        cvector res;
        res.x = b.x / x;
        res.y = b.y / y;
        return res;
    }

    cvector operator +(const double& i)const {
        cvector res;
        res.x = x + i;
        res.y = y + i;
        return res;
    }
    cvector operator -(const double& i)const {
        cvector res;
        res.x = x - i;
        res.y = y - i;
        return res;
    }
    cvector operator *(const double& i)const {
        cvector res;
        res.x = x * i;
        res.y = y * i;
        return res;
    }
    cvector operator /(const double& i)const {
        cvector res;
        res.x = x / i;
        res.y = y / i;
        return res;
    }
    double operator *(const cvector& b) {
        double res;
        res = x * b.x + y * b.y;
        return res;
    }
    double operator /(const cvector& b) {
        double res;
        res = x * b.x - y * b.y;
        return res;
    }
    bool operator == (const cvector &b)const{
        return(x == b.x) && (y == b.y);
    }
    bool operator !=(const cvector &b)const{
        return !(*this == b);
    }
    cvector& operator=(const cvector&b){
        x = b.x;
        y = b.y;
        return *this;
    }

};

cvector operator +(double x, const cvector &y){
    return y+x;
}
cvector operator -(double x, const cvector &y){
    return y-x;
}
cvector operator *(double x, const cvector &y){
    return y*x;
}
cvector operator /(double x, const cvector &y){
    return y/x;
}