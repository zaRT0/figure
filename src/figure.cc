#include <figure/figure.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#define PI 3.14

using namespace std;
using namespace Figures;

double calc_length(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

Circle::Circle(Point p1, Point p2) {
	points[0] = p1;
	points[1] = p2;
}

Point* Circle::get_points_framing_rectangle() {
	return points_framing_rectangle;
}

double Circle::calc_perimetr() {
	return round((2 * PI * calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * 10000) / 10000;
}

double Circle::calc_square() {
	return round((PI * pow(calc_length(points[0].x, points[1].x, points[0].y, points[1].y), 2)) * 10000) / 10000;
}

void Circle::calc_framing_rectangle()  {
	points_framing_rectangle[0].x = points[0].x;
	points_framing_rectangle[0].y = points[0].y + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
	points_framing_rectangle[1].x = points[1].x;
	points_framing_rectangle[1].y = points[1].y + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
	points_framing_rectangle[2] = { points[1].x, points[0].y };
	points_framing_rectangle[3] = { points[0].x, points[0].y };
}

FigurePtr Circle::clone_object() { return make_shared<Circle>(*this); }

Triangle::Triangle(Point p1, Point p2, Point p3) {
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
}

Point* Triangle::get_points_framing_rectangle() {
	return points_framing_rectangle;
}

double Triangle::calc_perimetr() {
	return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) * 10000) / 10000;
}

double Triangle::calc_square() {
	double p = (calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) / 2;
	return round((sqrt(p * (p - calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * (p - calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * (p - calc_length(points[0].x, points[2].x, points[0].y, points[2].y))) * 10000)) / 10000;
}

void Triangle::calc_framing_rectangle() {
	points_framing_rectangle[0].x = points[2].x;
	points_framing_rectangle[0].y = points[0].y;
	points_framing_rectangle[2].x = points[1].x;
	points_framing_rectangle[2].y = points[1].y;
	points_framing_rectangle[1] = { points[1].x, points[0].y };
	points_framing_rectangle[3] = { points[2].x, points[2].y };
}

FigurePtr Triangle::clone_object() { return make_shared<Triangle>(*this); }

Rectangle::Rectangle(Point p1, Point p2) {
	points[0] = p1;
	points[1] = p2;
}

Point* Rectangle::get_points_framing_rectangle() {
	return points_framing_rectangle;
}

double Rectangle::calc_perimetr() {
	points[2] = points[1];
	points[1] = Point(points[2].x, points[0].y);
	points[3] = Point(points[0].x, points[2].y);
	if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[2].x, points[3].x, points[2].y, points[3].y) + calc_length(points[0].x, points[3].x, points[0].y, points[3].y)) * 10000) / 10000; }
	else { return 0; }
}

double Rectangle::calc_square() {
	points[2] = points[1];
	points[1] = Point(points[2].x, points[0].y);
	points[3] = Point(points[0].x, points[2].y);
	if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) * calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * 10000) / 10000; }
	else { return 0; }
}

void Rectangle::calc_framing_rectangle() {
	points_framing_rectangle[0] = { points[0].x, points[0].y };
	points_framing_rectangle[2] = { points[1].x, points[1].y };
	points_framing_rectangle[1] = { points[1].x, points[0].y };
	points_framing_rectangle[3] = { points[0].x, points[1].y };
}

FigurePtr Rectangle::clone_object() { return make_shared<Rectangle>(*this); }