#include <figure/figure.h>
#include <stdexcept>
using namespace Figures;
using namespace std;

FigureContainer::FigureContainer(const FigureContainer& arr) {
    square_array.reserve(arr.size());
    for (const auto& seq : arr.square_array) {
        square_array.push_back(seq->clone_object());
    }
}

int FigureContainer::size() const {
	return square_array.size();
}

void FigureContainer::remove(int index) {
	if (index >= 0 && index < square_array.size()) {
		square_array.erase(square_array.begin() + index);
	}
}

void FigureContainer::insert(FigurePtr elem) {
	square_array.push_back(elem);
}

void FigureContainer::swap(FigureContainer& arr) {
	std::swap(this->square_array, arr.square_array);
}

FigurePtr FigureContainer::operator[](int index) const {
	if (index >= 0 && index < square_array.size()) {
		return square_array[index];
	}
	return nullptr;
}

FigureContainer& FigureContainer::operator=(FigureContainer& arr) {
	if (this != &arr) {
		FigureContainer temp(arr);
		square_array.swap(temp.square_array);
	}
	return *this;
}

int Figures::min_square(const FigureContainer& figures) {
    int last_index = -1;
    int min_value = 0;

    const auto size = figures.size();
    for (int i = 0; i < size; ++i) {
        const auto value = figures[i]->calc_square();
        if (last_index == -1 || value <= min_value) {
            last_index = i;
            min_value = value;
        }
    }

    return last_index;
}