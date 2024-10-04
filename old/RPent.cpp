#include "Poly.hpp"

class RegPentagon : public Polygon {
private:
    int length;
public:
    RegPentagon(int lengthh) {
        numSides = 5;
        length = lengthh;
    };

    double getPerimeter() {
        return numSides * numSides;
    };

    double getArea() {
        return length * getPerimeter() * .5;
    };
};