#pragma once

#include <cmath>

class vec3 {
public:
	double e[3];

    inline vec3() : e{0,0,0} {}
    inline vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    inline double x() const { return e[0]; }
    inline double y() const { return e[1]; }
    inline double z() const { return e[2]; }

    inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    inline double operator[](int i) const { return e[i]; }
    inline double& operator[](int i) { return e[i]; }

    inline vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    inline vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    inline vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    inline double length() const {
        return std::sqrt(length_squared());
    }

    inline double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};
