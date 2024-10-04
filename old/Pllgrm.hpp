
#ifndef PLLGRM_HPP
#define PLLGRM_HPP

class Rect {
private:
	double width;
	double length;

public:
	Rect(double l = 0, double w = 0);
	double getArea();
	double getPerimeter();
	double getLength() {return length;}
	double getWidth() {return width;}
};

class Pllgrm: public Rect {
private:
    double angle;

public:
    Pllgrm(double l = 0, double w = 0, double a = 0);
    double getArea();
    double getAngle() {return angle;}
    void setAngle(double a) {angle = a;}
};

#endif