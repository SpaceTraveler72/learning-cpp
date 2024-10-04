#ifndef RPENT.HPP
#define RPENT.HPP

#include "Poly.hpp"

class RegPentagon : public Polygon {
private:
    int length;
public:
    RegPentagon(int lengthh);
    double getArea();
    double getPerimeter();
};

#endif