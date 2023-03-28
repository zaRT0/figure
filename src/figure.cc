#include <figure/figure.h>
#include <stdexcept>
#include <cmath>
#define PI 3.14
using namespace Figures;
using namespace std;

Figure::Figure() : type(FigureType::TRIANGLE), points{ Point(), Point(), Point(), Point() } {}//определяем конструктор по умолчанию(массивы точек, тип треугольник)(инициализация значений)

//конструкторы, в которых точки записываются в массив

Figure::Figure(FigureType type, Point p1, Point p2) {
	this->type = type;
	points[0] = p1;
	points[1] = p2;
}

Figure::Figure(FigureType type, Point p1, Point p2, Point p3) {
	this->type = type;
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
}

Figure::Figure(FigureType type, Point p1, Point p2, Point p3, Point p4) {
	this->type = type;
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
}

FigureType Figure::get_type() const {//реализация метода для получения типа (
	return type;
}

double calc_length(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double Figure::calc_perimetr() {
	switch (type) {
	case CIRCLE: return round((2 * PI * calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * 10000) / 10000;
	case TRIANGLE: return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) * 10000) / 10000;
	case RECTANGLE:
		if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[2].x, points[3].x, points[2].y, points[3].y) + calc_length(points[0].x, points[3].x, points[0].y, points[3].y)) * 10000) / 10000; }
		else { return 0; }
	}
}

double Figure::calc_square() {
	switch (type) {
	case CIRCLE: return round((PI * pow(calc_length(points[0].x, points[1].x, points[0].y, points[1].y), 2)) * 10000) / 10000;
	case RECTANGLE:
		if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) * calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * 10000) / 10000; }
		else { return 0; }
	case TRIANGLE:
		double p = (calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) / 2;
		return round((sqrt(p * (p - calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * (p - calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * (p - calc_length(points[0].x, points[2].x, points[0].y, points[2].y))) * 10000)) / 10000;
	
	}
}

double Figure::calc_framing_rectangle() {
	switch (type) {
	case CIRCLE: return round((4 * pow(calc_length(points[0].x, points[1].x, points[0].y, points[1].y), 2)) * 10000) / 10000;
	case RECTANGLE: if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) * calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * 10000) / 10000; }
	case TRIANGLE: 
		double p = (calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) / 2;
		return  round((2 * sqrt(p * (p - calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * (p - calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * (p - calc_length(points[0].x, points[2].x, points[0].y, points[2].y))) * 10000)) / 10000;
	
	}
}