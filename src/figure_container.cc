#include <figure/figure.h>
#include <stdexcept>
using namespace Figures;
using namespace std;

FigureContainer::FigureContainer() : user_size(0) {}//конструктор по умолчанию

int FigureContainer::get_size() const {//реализация метода получения пользовательского размера массива
    return user_size;
}

Figure FigureContainer::operator[](int index) const {//реализация метода для работы с статическим массивом объектов класса(используется для доступа к элементам массива по индексу)
    if (index < 0 || user_size <= index) {
        throw runtime_error("Index out of range.");//ошибка (пытаемся вставить за рамки массива)
    }

    return square_array[index];//верни объект класса фигуре, которые лежат в масиве объектов класса фигуре
}

void FigureContainer::insert(int index, Figure s) {//метод для добавления в массив значения по индексу
    if (user_size == SIZE) {
        throw runtime_error("Full capacity reached.");//ошибка (пытаемся вставить за рамки массива)
    }

    for (int i = user_size - 1; i >= index; i--) {//цикл для сдвига массива
        square_array[i + 1] = square_array[i];
    }

    square_array[index] = s;
    ++user_size;
}

void FigureContainer::remove(int index) {//цикл для удаления элемента по индексу
    if (index < 0 || index >= user_size) {
        throw out_of_range("Invalid index.");//Не найден индекс (вылез за размерность массива)
    }

    for (int i = index; i < user_size - 1; i++) {
        square_array[i] = square_array[i + 1];
    }

    --user_size;
}

int Figures::min_square(const FigureContainer& figures) {//функция для вычисления минимальной площади
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