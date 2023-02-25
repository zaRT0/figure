#pragma once

enum FigureType {
	CIRCLE,
	TRIANGLE,
	RECTANGLE
};

class Figure {
	FigureType type;
public:
	Figure(FigureType type);
	double calc_perimetr(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4);
};