#include <figure/figure.h>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <algorithm>
#define PI 3.14
using namespace std;
using namespace Figures;

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

std::ostream& operator<<(std::ostream& out, Figure& figure) {
	Point* points_arr = figure.get_points_framing_rectangle();
	if (figure.get_type() == CIRCLE) {
		out << "  |Тип: " << "CIRCLE" << "|\n";
		out << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "\n";
	}
	else if (figure.get_type() == TRIANGLE) {
		out << "  |Тип: " << "TRIANGLE" << "|\n";
		out << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
		out << "\n";
	}
	else if (figure.get_type() == RECTANGLE) {
		out << "  |Тип: " << "RECTANGLE" << "|\n";
		out << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
		out << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
		out << "\n";
	}
	return out;
}


FigureType Figure::get_type() const {
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
		points_framing_rectangle[0].x = points[0].x;
		points_framing_rectangle[0].y = points[0].y + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
		points_framing_rectangle[1].x = points[1].x;
		points_framing_rectangle[1].y = points[1].y + sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
		points_framing_rectangle[2] = { points[1].x, points[0].y };
		points_framing_rectangle[3] = { points[0].x, points[0].y };
		break;
	case RECTANGLE:
		points_framing_rectangle[0] = { points[0].x, points[0].y };
		points_framing_rectangle[2] = { points[1].x, points[1].y };
		points_framing_rectangle[1] = { points[1].x, points[0].y };
		points_framing_rectangle[3] = { points[0].x, points[1].y };
		break;
	case TRIANGLE:
		points_framing_rectangle[0].x = points[2].x;
		points_framing_rectangle[0].y = points[0].y;
		points_framing_rectangle[2].x = points[1].x;
		points_framing_rectangle[2].y = points[1].y;
		points_framing_rectangle[1] = { points[1].x, points[0].y };
		points_framing_rectangle[3] = { points[2].x, points[2].y };
		break;
	}
}

Point* Figure::get_points_framing_rectangle() {
	return points_framing_rectangle;
}