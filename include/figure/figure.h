#pragma once
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
	public:
		Figure();//конструктор по умолчанию
		//создаем конструкторы для каждого типа фигуры
		Figure(FigureType type, Point p1, Point p2);
		Figure(FigureType type, Point p1, Point p2, Point p3);
		Figure(FigureType type, Point p1, Point p2, Point p3, Point p4);
		FigureType get_type() const;// метод для получения типа фигуры (геттер)
		double calc_perimetr();//данные определяются конструкторами, поэтому ничего не передаем (передаем значение извне)
		double calc_square();
		double calc_framing_rectangle();
	};

	class FigureContainer {//класс фигурконтейнер, в котором определяем методы по общему заданию
	public:
		static const int SIZE = 10;//определяем размер массива
	private:
		Figure square_array[SIZE];//массив объектов класса фигур, в который положим значения площадей прямоугольников
		int user_size;//пользовательский размер
	public:
		FigureContainer();//конструктор по умолчанию(для инициализации данных)
		int get_size() const;//метод для получения пользовательского размера массива
		void remove(int index);//метод для удаления значения по указанному индексу
		void insert(int index, Figure s);//метод для добавления значения в массив по указанному индексу
		Figure operator[](int index) const;//метод для работы с статическим массивом объектов класса(используется для доступа к элементам массива по индексу)
	};

	int min_square(const FigureContainer& figures);//функция для поиска мин площади в массиве(передаем массив по ссылке)
}