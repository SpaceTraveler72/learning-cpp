#include "Pllgrm.hpp"
#include <math.h>

Rect::Rect(double l, double w) {
    length = l;
    width = w;
}

double Rect::getArea() {
    return length*width;
}

double Rect::getPerimeter() {
    return 2*length + 2*width;
}


Pllgrm::Pllgrm(double l, double w, double a) : Rect(l, w) {
    angle = a;
}

double Pllgrm::getArea() {
    return Rect::getArea() * sin(angle * (3.141592/180));
}