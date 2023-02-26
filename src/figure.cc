#include <figure/figure.h>
#include <cmath>
#define PI 3.14

Figure::Figure(FigureType type) {
	this->type = type;
}

Figure::Figure(double cirlce_square, double triangle_square, double rectangle_square) {
	this->cirlce_square = cirlce_square;
	this->triangle_square = triangle_square;
	this->rectangle_square = rectangle_square;
}

double calc_length(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double Figure::calc_perimetr(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4) {
	switch (type) {
	case CIRCLE: return round((2 * PI * calc_length(x1, x2, y1, y2)) * 10000) / 10000;
	case TRIANGLE: return round((calc_length(x1, x2, y1, y2) + calc_length(x2, x3, y2, y3) + calc_length(x1, x3, y1, y3)) * 10000) / 10000;
	case RECTANGLE:
		if ((y1 == y2) && (x1 == x4) && (y3 == y4) && (x2 == x3)) { return round((calc_length(x1, x2, y1, y2) + calc_length(x2, x3, y2, y3) + calc_length(x3, x4, y3, y4) + calc_length(x1, x4, y1, y4)) * 10000) / 10000; }
		else { return 0; }
	}
}

double Figure::calc_square(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4) {
	switch (type) {
	case CIRCLE: return round((PI * pow(calc_length(x1, x2, y1, y2), 2)) * 10000) / 10000;
	case RECTANGLE:
		if ((y1 == y2) && (x1 == x4) && (y3 == y4) && (x2 == x3)) { return round((calc_length(x1, x2, y1, y2) * calc_length(x2, x3, y2, y3)) * 10000) / 10000; }
		else { return 0; }
	case TRIANGLE:
		double p = (calc_length(x1, x2, y1, y2) + calc_length(x2, x3, y2, y3) + calc_length(x1, x3, y1, y3)) / 2;
		return round((sqrt(p * (p - calc_length(x1, x2, y1, y2)) * (p - calc_length(x2, x3, y2, y3)) * (p - calc_length(x1, x3, y1, y3))) * 10000)) / 10000;
	}
}

double Figure::calc_framing_rectangle(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4) {
	switch (type) {
	case CIRCLE: return round((4 * pow(calc_length(x1, x2, y1, y2), 2)) * 10000) / 10000;
	case RECTANGLE: if ((y1 == y2) && (x1 == x4) && (y3 == y4) && (x2 == x3)) { return round((calc_length(x1, x2, y1, y2) * calc_length(x2, x3, y2, y3)) * 10000) / 10000; }
	case TRIANGLE: 
		double p = (calc_length(x1, x2, y1, y2) + calc_length(x2, x3, y2, y3) + calc_length(x1, x3, y1, y3)) / 2;
		return  round((2 * sqrt(p * (p - calc_length(x1, x2, y1, y2)) * (p - calc_length(x2, x3, y2, y3)) * (p - calc_length(x1, x3, y1, y3))) * 10000)) / 10000;
	}
}

int Figure::min_square(double cirlce_square, double triangle_square, double rectangle_square) {
	if (cirlce_square < triangle_square && cirlce_square < rectangle_square) {return 0;}
	if (triangle_square < cirlce_square && triangle_square < rectangle_square) {return 1;}
	if (rectangle_square < triangle_square && rectangle_square < cirlce_square) {return 2;}
}