#include <figure/figure.h>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#define PI 3.14
using namespace Figures;
using namespace std;

Figure::Figure() : type(FigureType::TRIANGLE), points{ Point(), Point(), Point(), Point() } {}//���������� ����������� �� ���������(������� �����, ��� �����������)(������������� ��������)

//������������, � ������� ����� ������������ � ������

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

std::ostream& Figures::operator<<(std::ostream& out, Figure& figure) {
	Point* points_arr = figure.get_points();
	if (figure.get_type() == CIRCLE) {
		out << "  |���: " << "RECTANGLE" << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "\n";
	}
	else if (figure.get_type() == TRIANGLE) {
		out << "  |���: " << "RECTANGLE" << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
		out << "\n";
	}
	else if (figure.get_type() == RECTANGLE) {
		out << "  |���: " << "RECTANGLE" << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |������ �����: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "\n";
	}
	return out;
}

FigureType Figure::get_type() const {//���������� ������ ��� ��������� ���� (
	return type;
}

Point* Figure::get_points_framing_rectangle() {
	return points_framing_rectangle;
}

Point* Figure::get_points() {
	return points_framing_rectangle;
}

double calc_length(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double Figure::calc_perimetr() {
	switch (type) {
	case CIRCLE: return round((2 * PI * calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * 10000) / 10000;
	case TRIANGLE: return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) * 10000) / 10000;
	case RECTANGLE:
		points[2] = points[1];
		points[1] = Point(points[2].x, points[0].y);
		points[3] = Point(points[0].x, points[2].y);
		if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[2].x, points[3].x, points[2].y, points[3].y) + calc_length(points[0].x, points[3].x, points[0].y, points[3].y)) * 10000) / 10000; }
		else { return 0; }
	}
}

double Figure::calc_square() {
	switch (type) {
	case CIRCLE: return round((PI * pow(calc_length(points[0].x, points[1].x, points[0].y, points[1].y), 2)) * 10000) / 10000;
	case RECTANGLE:
		points[2] = points[1];
		points[1] = Point(points[2].x, points[0].y);
		points[3] = Point(points[0].x, points[2].y);
		if ((points[0].y == points[1].y) && (points[0].x == points[3].x) && (points[2].y == points[3].y) && (points[1].x == points[2].x)) { return round((calc_length(points[0].x, points[1].x, points[0].y, points[1].y) * calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * 10000) / 10000; }
		else { return 0; }
	case TRIANGLE:
		double p = (calc_length(points[0].x, points[1].x, points[0].y, points[1].y) + calc_length(points[1].x, points[2].x, points[1].y, points[2].y) + calc_length(points[0].x, points[2].x, points[0].y, points[2].y)) / 2;
		return round((sqrt(p * (p - calc_length(points[0].x, points[1].x, points[0].y, points[1].y)) * (p - calc_length(points[1].x, points[2].x, points[1].y, points[2].y)) * (p - calc_length(points[0].x, points[2].x, points[0].y, points[2].y))) * 10000)) / 10000;
	
	}
}

void Figure::calc_framing_rectangle() {
    switch (type) {
    case CIRCLE:
        points_framing_rectangle[0].x = points[0].x - sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
        points_framing_rectangle[0].y = points[0].y - sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
        points_framing_rectangle[1].x = points[0].x + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
        points_framing_rectangle[1].y = points[0].y + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
        points_framing_rectangle[2] = points[0];
        points_framing_rectangle[3] = points[1];
        break;
    case RECTANGLE:
		points_framing_rectangle[0] = { min({ points[0].x, points[1].x, points[2].x, points[3].x }), min({ points[0].y, points[1].y, points[2].y, points[3].y }) };
		points_framing_rectangle[1] = { max({ points[0].x, points[1].x, points[2].x, points[3].x }), max({ points[0].y, points[1].y, points[2].y, points[3].y }) };
		points_framing_rectangle[2] = { min({ points[0].x, points[1].x, points[2].x, points[3].x }), max({ points[0].y, points[1].y, points[2].y, points[3].y }) };
		points_framing_rectangle[3] = { max({ points[0].x, points[1].x, points[2].x, points[3].x }), min({ points[0].y, points[1].y, points[2].y, points[3].y }) };
        break;
    case TRIANGLE:
		points[2] = points[1];
		points[1] = Point(points[2].x, points[0].y);
		points[3] = Point(points[0].x, points[2].y);
        points_framing_rectangle[0] = { min({ points[0].x, points[1].x, points[2].x }), min({ points[0].y, points[1].y, points[2].y }) };
        points_framing_rectangle[1] = { max({ points[0].x, points[1].x, points[2].x }), max({ points[0].y, points[1].y, points[2].y }) };
        points_framing_rectangle[2] = { min({ points[0].x, points[1].x, points[2].x }), max({ points[0].y, points[1].y, points[2].y }) };
        points_framing_rectangle[3] = { max({ points[0].x, points[1].x, points[2].x }), min({ points[0].y, points[1].y, points[2].y }) };
		break;
    }
}

void Figure::set_points(const Figure& elem, double x1, double y1, double x2, double y2) {
	points[0] = Point(x1, y1);
	points[1] = Point(x2, y2);
}

void Figure::set_points(const Figure& elem, double x1, double y1, double x2, double y2, double x3, double y3) {
	points[0] = Point(x1, y1);
	points[1] = Point(x2, y2);
	points[2] = Point(x3, y3);
}