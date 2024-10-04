
class Rect {
private:
	double width;
	double length;

public:
	Rect(double l=0, double w=0);
	double getArea();
	double getPerimeter();
	double getLength() {return length;}
	double getWidth() {return width;}
};
