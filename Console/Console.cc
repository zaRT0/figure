#include <iostream>
#include <stdlib.h>
#include <figure/figure.h>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;
using namespace Figures;

int get_key() {
    int key = _getch();
    if ((key == 0) || (key == 224)) key = _getch();
    return key;
}

void print_arr(FigureContainer& arr) {
    system("cls");
    if (arr.get_size() == 0) {
        cout << "Массив объектов пуст" << endl;
        return;
    }
    for (int i = 0; i < arr.get_size(); ++i) {
        cout << "[" << i << "]" << endl;
        cout << arr[i];
    }
    cout << endl;
    cout << "Для продолжения нажмите любую кнопку ";
    get_key();
}

int input_index(int size) {
    int index = -1;
    while (true) {
        cout << "Введите индекс или -1, если хотите выйти: ";
        if (!(cin >> index) || index < -1 || index >= size) {
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << "Неверный индекс или ввод!" << endl;
            continue;
        }
        if (index == -1) {
            cout << "Выход из программы." << endl;
            break;
        }
        index--;
        break;
    }
    return index;
}

void add_item(FigureContainer& arr) {
    system("cls");
    int index = input_index(arr.get_size());
    if (index != -1) {
        string figure_types[] = { "CIRCLE", "TRIANGLE", "RECTANGLE" };
        FigureType arr_enum[] = { CIRCLE, TRIANGLE, RECTANGLE };
        int choose = 0;
        int flag = true;
        system("cls");
        while (flag) {
            cout << "|Выберите тип фигуры|" << endl;
            cout << "1)" << "|CIRCLE|" << endl;
            cout << "2)" << "|TRIANGLE|" << endl;
            cout << "3)" << "|RECTANGLE|" << endl;
            int seq_type = get_key();
            if (seq_type == 49) { choose = 0; flag = false; }
            else if (seq_type == 50) { choose = 1; flag = false; }
            else if (seq_type == 51) { choose = 2; flag = false; }
            else { cout << "Введено неправильное число, попробуйте ещё раз" << endl; }
        }
        system("cls");
        Figure item;
        if (choose == 0) {
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            cout << "Выбранный тип CIRCLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2));
        }else if (choose == 1) {
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3, y3;
            cout << "Выбранный тип TRIANGLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            cout << "Введите координаты третьей точки через пробел(x y): ";
            cin >> x3 >> y3;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2), Point(x3, y3));
        }else{
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            cout << "Выбранный тип RECTANGLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2));
        }
         arr.insert(index, item);
    }
}


void delete_item(FigureContainer& arr) {
    int index = input_index(arr.get_size());
    if (index != -1) {
        arr.remove(index);
    }
}

void find_min_square(FigureContainer& arr) {
    system("cls");
    int index = min_square(arr);
    cout << "Фигура с минимальной площадью: " << endl;
    cout << arr[index];
    get_key();
}

void change_figure(FigureContainer& arr) {
    system("cls");
    int index = input_index(arr.get_size());
    if (index != -1) {
        string figure_types[] = { "CIRCLE", "TRIANGLE", "RECTANGLE" };
        FigureType arr_enum[] = { CIRCLE, TRIANGLE, RECTANGLE };
        int choose = 0;
        int flag = true;
        system("cls");
        while (flag) {
            cout << "|Выберите тип фигуры|" << endl;
            cout << "1)" << "|CIRCLE|" << endl;
            cout << "2)" << "|TRIANGLE|" << endl;
            cout << "3)" << "|RECTANGLE|" << endl;
            int seq_type = get_key();
            if (seq_type == 49) { choose = 0; flag = false; }
            else if (seq_type == 50) { choose = 1; flag = false; }
            else if (seq_type == 51) { choose = 2; flag = false; }
            else { cout << "Введено неправильное число, попробуйте ещё раз" << endl; }
        }
        system("cls");
        Figure item;
        if (choose == 0) {
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            cout << "Выбранный тип CIRCLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2));
        }
        else if (choose == 1) {
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3, y3;
            cout << "Выбранный тип TRIANGLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            cout << "Введите координаты третьей точки через пробел(x y): ";
            cin >> x3 >> y3;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2), Point(x3, y3));
        }
        else {
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            cout << "Выбранный тип RECTANGLE" << endl;
            cout << "Введите координаты первой точки через пробел(x y): ";
            cin >> x1 >> y1;
            cout << "Введите координаты второй точки через пробел(x y): ";
            cin >> x2 >> y2;
            item = Figure(arr_enum[choose], Point(x1, y1), Point(x2, y2));
        }
        arr.insert(index, item);
    }
}


int menu1() {
    cout << "1)" << "Добавить последовательность в массив по индексу" << endl;
    cout << "2)" << "Удалить последовательность из массива по индексу" << endl;
    cout << "3)" << "Вывести последовательности на экран" << endl;
    cout << "4)" << "Вывести последовательность с минимальным n-ым членом" << endl;
    cout << "5)" << "Заменить последовательность из массива по индексу" << endl;
    cout << "6)" << "Выйти" << endl;

    while (true) {
        int key = get_key();
        if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54)) return key;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    FigureContainer array;
    while (true) {
        system("cls");
        cout << "Меню:" << endl;
        int m1 = menu1();
        if (m1 == 49) { system("cls"); add_item(array); }
        if (m1 == 50) { delete_item(array); }
        if (m1 == 51) { print_arr(array); };
        if (m1 == 52) { find_min_square(array); };
        if (m1 == 53) { change_figure(array); };
        if (m1 == 54) break;
    }
    return 0;
}