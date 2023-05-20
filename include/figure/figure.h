#pragma once
#include <string>
#include <memory>
#include <vector>
namespace Figures {//Создаем пространство имен для удобства, в котором определяем все классы и сопутствующие им структуры (все типы данных)
	struct Point {//структура поинт для описания точек на плоскости
		double x;
		double y;
		Point() {//конструктор по умолчанию для инициализации координат
			this->x = 0;
			this->y = 0;
		}
		Point(double x, double y) {//конструктор для инициализации координат собственными значениями
			this->x = x;
			this->y = y;
		}
	};

	class Figure;
	using FigurePtr = std::shared_ptr<Figure>;

	class Figure {
	public:
		virtual ~Figure() = default;
		virtual double calc_perimetr() = 0;
		virtual double calc_square() = 0;
		virtual void calc_framing_rectangle() = 0;
		virtual FigurePtr clone_object() = 0;
	protected:
		Figure() = default;
		Figure(const Figure&) = default;
		Figure& operator=(const Figure&) = default;
	};

	class Circle : public Figure {
	private:
		Point points[2];
		Point points_framing_rectangle[4];
	public:
		Circle(Point p1, Point p2);
		Point* get_points_framing_rectangle();
		double calc_perimetr () override;
		double calc_square() override;
		void calc_framing_rectangle() override;
		FigurePtr clone_object() override;
	};

	class Triangle : public Figure {
	private:
		Point points[3];
		Point points_framing_rectangle[4];
	public:
		Triangle(Point p1, Point p2, Point p3);
		Point* get_points_framing_rectangle() ;
		double calc_perimetr() override;
		double calc_square() override;
		void calc_framing_rectangle() override;
		FigurePtr clone_object() override;
	};

	class Rectangle : public Figure {
	private:
		Point points[4];
		Point points_framing_rectangle[4];
	public:
		Rectangle(Point p1, Point p2);
		Point* get_points_framing_rectangle() ;
		double calc_perimetr() override;
		double calc_square() override;
		void calc_framing_rectangle() override;
		FigurePtr clone_object() override;
	};

	class FigureContainer {
	private:
		std::vector<FigurePtr> square_array;
	public:
		FigureContainer() = default;
		FigureContainer(const FigureContainer& arr);
		int size() const;
		void remove(int index);
		void insert(FigurePtr s);
		void swap(FigureContainer& arr);
		FigurePtr operator[](int index) const;
		FigureContainer& operator=(FigureContainer& arr);
	};
	int min_square(const FigureContainer& figures);
}