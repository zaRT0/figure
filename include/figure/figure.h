#pragma once
#include <string>
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

	enum FigureType {//тип перечисления для типов фигур
		CIRCLE,
		TRIANGLE,
		RECTANGLE
	};

	class Figure {//создаем класс фигур(эквивалентый Item), в котором определяем методы по основному заданию
		FigureType type; //переменная type для определения типа фигуры
		Point points[4];//массив стурктур для точек
		Point points_framing_rectangle[4];
	public:
		Figure();//конструктор по умолчанию
		//создаем конструкторы для каждого типа фигуры
		Figure(FigureType type, Point p1, Point p2);
		Figure(FigureType type, Point p1, Point p2, Point p3);
		FigureType get_type() const;// метод для получения типа фигуры (геттер)
		Point* get_points_framing_rectangle();
		Point* get_points();
		void set_points(const Figure& elem, double x1, double y1, double x2, double y2);
		void set_points(const Figure& elem, double x1, double y1, double x2, double y2, double x3, double y3);
		double calc_perimetr();//данные определяются конструкторами, поэтому ничего не передаем (передаем значение извне)
		double calc_square();
		void calc_framing_rectangle();
		friend std::ostream& operator<<(std::ostream& out, Figure& figure);

	};

	class FigureContainer {//класс фигурконтейнер, в котором определяем методы по общему заданию
	private:
		Figure** square_array;//массив объектов класса фигур, в который положим значения площадей прямоугольников
		int user_size;//пользовательский размер
	public:
		~FigureContainer();
		FigureContainer(int size);
		FigureContainer(const FigureContainer& arr);
		FigureContainer() : user_size(0), square_array(nullptr) {};
		int get_size() const;//метод для получения пользовательского размера массива
		void remove(int index);//метод для удаления значения по указанному индексу
		void insert(int index, Figure& s);//метод для добавления значения в массив по указанному индексу
		void swap(FigureContainer& arr);
		Figure operator[](int index) const;
		Figure& operator[](int index);
		FigureContainer& operator=(FigureContainer arr);
	};

	int min_square(const FigureContainer& figures);//функция для поиска мин площади в массиве(передаем массив по ссылке)
}