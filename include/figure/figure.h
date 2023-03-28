#pragma once
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
	public:
		Figure();//����������� �� ���������
		//������� ������������ ��� ������� ���� ������
		Figure(FigureType type, Point p1, Point p2);
		Figure(FigureType type, Point p1, Point p2, Point p3);
		Figure(FigureType type, Point p1, Point p2, Point p3, Point p4);
		FigureType get_type() const;// ����� ��� ��������� ���� ������ (������)
		double calc_perimetr();//������ ������������ ��������������, ������� ������ �� �������� (�������� �������� �����)
		double calc_square();
		double calc_framing_rectangle();
	};

	class FigureContainer {//����� ��������������, � ������� ���������� ������ �� ������ �������
	public:
		static const int SIZE = 10;//���������� ������ �������
	private:
		Figure square_array[SIZE];//������ �������� ������ �����, � ������� ������� �������� �������� ���������������
		int user_size;//���������������� ������
	public:
		FigureContainer();//����������� �� ���������(��� ������������� ������)
		int get_size() const;//����� ��� ��������� ����������������� ������� �������
		void remove(int index);//����� ��� �������� �������� �� ���������� �������
		void insert(int index, Figure s);//����� ��� ���������� �������� � ������ �� ���������� �������
		Figure operator[](int index) const;//����� ��� ������ � ����������� �������� �������� ������(������������ ��� ������� � ��������� ������� �� �������)
	};

	int min_square(const FigureContainer& figures);//������� ��� ������ ��� ������� � �������(�������� ������ �� ������)
}