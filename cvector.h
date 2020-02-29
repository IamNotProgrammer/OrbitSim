#ifndef OSIM1_CVECTOR_H
#define OSIM1_CVECTOR_H

#include <cmath>

class cvector {
public:

    double x{};
    double y{};

    cvector() = default;

    cvector(const double &a, const double &b) {
        cvector res;
        res.x = a;
        res.y = b;
    }

    cvector operator+(const cvector &b) const {
        cvector res;
        res.x = b.x + x;
        res.y = b.y + y;
        return res;
    }

    cvector operator-(const cvector &b) const {
        cvector res;
        res.x = b.x - x;
        res.y = b.y - y;
        return res;
    }

    cvector operator+(const double &i) const {
        cvector res;
        res.x = x + i;
        res.y = y + i;
        return res;
    }

    cvector operator-(const double &i) const {
        cvector res;
        res.x = x - i;
        res.y = y - i;
        return res;
    }

    cvector operator*(const double &i) const {
        cvector res;
        res.x = x * i;
        res.y = y * i;
        return res;
    }

    cvector operator/(const double &i) const {
        cvector res;
        res.x = x / i;
        res.y = y / i;
        return res;
    }

    double operator*(const cvector &b) {
        double res;
        res = x * b.x + y * b.y;
        return res;
    }

    double operator/(const cvector &b) {
        double res;
        res = x * b.x - y * b.y;
        return res;
    }

    bool operator==(const cvector &b) const {
        return (x == b.x) && (y == b.y);
    }

    bool operator!=(const cvector &b) const {
        return !(*this == b);
    }

    cvector &operator=(const cvector &b) {
        x = b.x;
        y = b.y;
        return *this;
    }

    cvector operator+=(const cvector &b) {
        x = b.x + x;
        y = b.y + y;
        return *this;
    }

    cvector operator-=(const cvector &b) {
        x = x - b.x;
        y = y - b.y;
        return *this;
    }

    cvector operator-() const {
        cvector res;
        res.x = -x;
        res.y = -y;
        return res;
    }
};

double abs(const cvector &vi) {
    return sqrt(vi.x * vi.x + vi.y * vi.y);
}

cvector operator+(double x, const cvector &y) {
    return y + x;
}

cvector operator-(double x, const cvector &y) {
    return y - x;
}

cvector operator*(double x, const cvector &y) {
    return y * x;
}

cvector operator/(double x, const cvector &y) {
    return y / x;
}

#endif //OSIM1_CVECTOR_H
