#pragma once
#include <string>
namespace Figures {//������� ������������ ���� ��� ��������, � ������� ���������� ��� ������ � ������������� �� ��������� (��� ���� ������)
	struct Point {//��������� ����� ��� �������� ����� �� ���������
		double x;
		double y;
		Point() {//����������� �� ��������� ��� ������������� ���������
			this->x = 0;
			this->y = 0;
		}
		Point(double x, double y) {//����������� ��� ������������� ��������� ������������ ����������
			this->x = x;
			this->y = y;
		}
	};

	enum FigureType {//��� ������������ ��� ����� �����
		CIRCLE,
		TRIANGLE,
		RECTANGLE
	};

	class Figure {//������� ����� �����(������������ Item), � ������� ���������� ������ �� ��������� �������
		FigureType type; //���������� type ��� ����������� ���� ������
		Point points[4];//������ �������� ��� �����
		Point points_framing_rectangle[4];
	public:
		Figure();//����������� �� ���������
		//������� ������������ ��� ������� ���� ������
		Figure(FigureType type, Point p1, Point p2);
		Figure(FigureType type, Point p1, Point p2, Point p3);
		FigureType get_type() const;// ����� ��� ��������� ���� ������ (������)
		Point* get_points_framing_rectangle();//������� ���������� ������ �� ������ �����
		double calc_perimetr();//������ ������������ ��������������, ������� ������ �� �������� (�������� �������� �����)
		double calc_square();
		void calc_framing_rectangle();
		friend std::ostream& operator<<(std::ostream& out, Figure& figure);//���������� ��������� ������, ��������� �� ���� ����� ������ � ������� ������ �����.
	};
	class FigureContainer {//����� ��������������, � ������� ���������� ������ �� ������ �������
	private:
		Figure** square_array;//������ ����������, ���������� ���������
		int user_size;//���������������� ������
	public:
		~FigureContainer();//���������� ��� �������� ������ ��� ������ ����������
		FigureContainer(int size);
		FigureContainer(const FigureContainer& arr);//����������� �����������
		FigureContainer() : user_size(0), square_array(nullptr) {};//����������� �� ���������. ��� �����������
		int get_size() const;//����� ��� ��������� ����������������� ������� �������
		void remove(int index);//����� ��� �������� �������� �� ���������� �������
		void insert(int index, Figure& s);//����� ��� ���������� �������� � ������ �� ���������� �������
		void swap(FigureContainer& arr);//������� ��� ������������ �����������. 
		Figure operator[](int index) const;//���������� ��������� ���������� ������
		Figure& operator[](int index);
		FigureContainer& operator=(FigureContainer arr);//���������� �������� �����
	};

	int min_square(const FigureContainer& figures);//������� ��� ������ ��� ������� � �������(�������� ������ �� ������)
}