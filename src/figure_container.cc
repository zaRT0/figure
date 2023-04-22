#include <figure/figure.h>
#include <stdexcept>
using namespace Figures;
using namespace std;

FigureContainer::~FigureContainer() {
    for (int i = 0; i < user_size; i++) {
        delete square_array[i];
    }
    delete[] square_array;
}

FigureContainer::FigureContainer(const FigureContainer& arr) {
    user_size = arr.user_size;
    square_array = new Figure * [user_size];
    for (int i = 0; i < user_size; i++) {
        square_array[i] = new Figure(*arr.square_array[i]);
    }
}

FigureContainer::FigureContainer(int size) {
    if (size < 0) throw std::invalid_argument("Size of array should be positive");
    user_size = size;
    square_array = new Figure * [size];
    for (int i = 0; i < size; i++) {
        square_array[i] = new Figure();
    }
}

Figure& FigureContainer::operator[](int index) {
    if (index < 0 || index >= user_size) { throw out_of_range("Index out of range."); }
    return *(square_array[index]);
}


Figure FigureContainer::operator[](int index) const {
    if (index < 0 || index >= user_size) {
        throw out_of_range("Index out of range.");
    }
    return *(square_array[index]);
}


FigureContainer& ::FigureContainer::operator=(FigureContainer arr) {
    this->swap(arr);
    return *this;
}


void FigureContainer::swap(FigureContainer& arr) {
    std::swap(user_size, arr.user_size);
    std::swap(square_array, arr.square_array);
}


int FigureContainer::get_size() const {//реализация метода получения пользовательского размера массива
    return user_size;
}


void FigureContainer::insert(int index, Figure& s) {
    if (index > user_size || index < 0) { throw out_of_range("Invalid index"); }
    Figure** new_square_array = new Figure * [user_size + 1];

    for (int i = 0; i < index; i++) {
        new_square_array[i] = square_array[i];
    }

    new_square_array[index] = new Figure(s);
    ++user_size;

    for (int i = index + 1; i < user_size; i++) {
        new_square_array[i] = square_array[i - 1];
    }

    delete[] square_array;
    square_array = new_square_array;
}

void FigureContainer::remove(int index) {
    if (index < 0 || index >= user_size) {
        throw out_of_range("Invalid index.");
    }

    delete square_array[index];
    square_array[index] = nullptr;

    for (int i = index; i < user_size - 1; i++) {
        square_array[i] = square_array[i + 1];
    }

    square_array[user_size - 1] = nullptr;
    user_size--;
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