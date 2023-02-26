#pragma once

enum FigureType {
	CIRCLE,
	TRIANGLE,
	RECTANGLE
};

class Figure {
	FigureType type;
	double cirlce_square, triangle_square, rectangle_square;
public:
	Figure(FigureType type);
	Figure(double cirlce_square, double triangle_square, double rectangle_square);
	double calc_perimetr(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
	double calc_square(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
	double calc_framing_rectangle(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
	int min_square(double cirlce_square, double triangle_square, double rectangle_square);
};