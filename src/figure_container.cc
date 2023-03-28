#include <figure/figure.h>
#include <stdexcept>
using namespace Figures;
using namespace std;

FigureContainer::FigureContainer() : user_size(0) {}//����������� �� ���������

int FigureContainer::get_size() const {//���������� ������ ��������� ����������������� ������� �������
    return user_size;
}

Figure FigureContainer::operator[](int index) const {//���������� ������ ��� ������ � ����������� �������� �������� ������(������������ ��� ������� � ��������� ������� �� �������)
    if (index < 0 || user_size <= index) {
        throw runtime_error("Index out of range.");//������ (�������� �������� �� ����� �������)
    }

    return square_array[index];//����� ������ ������ ������, ������� ����� � ������ �������� ������ ������
}

void FigureContainer::insert(int index, Figure s) {//����� ��� ���������� � ������ �������� �� �������
    if (user_size == SIZE) {
        throw runtime_error("Full capacity reached.");//������ (�������� �������� �� ����� �������)
    }

    for (int i = user_size - 1; i >= index; i--) {//���� ��� ������ �������
        square_array[i + 1] = square_array[i];
    }

    square_array[index] = s;
    ++user_size;
}

void FigureContainer::remove(int index) {//���� ��� �������� �������� �� �������
    if (index < 0 || index >= user_size) {
        throw out_of_range("Invalid index.");//�� ������ ������ (����� �� ����������� �������)
    }

    for (int i = index; i < user_size - 1; i++) {
        square_array[i] = square_array[i + 1];
    }

    --user_size;
}

int Figures::min_square(const FigureContainer& figures) {//������� ��� ���������� ����������� �������
    int last_index = -1;
    int min_value = 0;

    const auto size = figures.get_size();
    for (int i = 0; i < size; ++i) {
        const auto value = figures[i].calc_square();
        if (last_index == -1 || value <= min_value) {
            last_index = i;
            min_value = value;
        }
    }

    return last_index;
}