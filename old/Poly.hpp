#ifndef POLY
#define POLY

class Polygon {
    protected:
        int numSides;
        Polygon();
    public:
        int getNumSides();
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
};
#endif
