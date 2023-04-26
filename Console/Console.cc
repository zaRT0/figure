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
        arr[i].calc_framing_rectangle();
        Point* points_arr = arr[i].get_points_framing_rectangle();
        if (arr[i].get_type() == CIRCLE) {
            cout << "  |Тип: " << "CIRCLE" << "|\n";
            cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
            cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
            cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
            cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
            cout << "\n";
        }
        else if (arr[i].get_type() == TRIANGLE) {
            cout << "  |Тип: " << "TRIANGLE" << "|\n";
            cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
            cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
            cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
            cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
            cout << "\n";
        }
        else if (arr[i].get_type() == RECTANGLE) {
            cout << "  |Тип: " << "RECTANGLE" << "|\n";
            cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
            cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
            cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
            cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
            cout << "\n";
        }
    }
    cout << endl;
    cout << "Для продолжения нажмите любую кнопку ";
    get_key();
}

int input_index(int size) {
    bool flag = true;
    int index = 0;
    while (flag) {
        cout << "Введите индекс или -1, если хотите выйти: " << endl;
        cin >> index;
        if (index == -1) {
            cout << "Выход из программы." << endl;
            return -1;
        }
        if (cin.fail() || index < 0 || index >= size + 1) {
            cin.clear();
            system("cls");
            cout << "Неверный индекс или ввод!" << endl;
        }
        else { flag = false;}
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
            double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
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
    system("cls");
    if (arr.get_size() == 0) { return; }
    int index = input_index(arr.get_size());
    if (index != -1) {
        arr.remove(index);
    }
}

void find_min_square(FigureContainer& arr) {
    system("cls");
    int index = min_square(arr);
    cout << "Фигура с минимальной площадью: " << endl;
    arr[index].calc_framing_rectangle();
    Point* points_arr = arr[index].get_points_framing_rectangle();
    if (arr[index].get_type() == CIRCLE) {
        cout << "  |Тип: " << "CIRCLE" << "|\n";
        cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
        cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
        cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
        cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
        cout << "\n";
    }
    else if (arr[index].get_type() == TRIANGLE) {
        cout << "  |Тип: " << "TRIANGLE" << "|\n";
        cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
        cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
        cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
        cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
        cout << "\n";
    }
    else if (arr[index].get_type() == RECTANGLE) {
        cout << "  |Тип: " << "RECTANGLE" << "|\n";
        cout << "  |Первая точка: " << "X - " << points_arr[0].x << " Y - " << points_arr[0].y << "|\n";
        cout << "  |Вторая точка: " << "X - " << points_arr[1].x << " Y - " << points_arr[1].y << "|\n";
        cout << "  |Третья точка: " << "X - " << points_arr[2].x << " Y - " << points_arr[2].y << "|\n";
        cout << "  |Четвёртая точка: " << "X - " << points_arr[3].x << " Y - " << points_arr[3].y << "|\n";
        cout << "\n";
    }
    cout << endl;
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
        arr.remove(index);
        arr.insert(index, item);
    }
}

int menu1() {
    cout << "1)" << "Добавить фигуру в массив по индексу" << endl;
    cout << "2)" << "Удалить фигуру из массива по индексу" << endl;
    cout << "3)" << "Вывести кординаты фигуры на экран" << endl;
    cout << "4)" << "Вывести фигурe с минимальной площадью" << endl;
    cout << "5)" << "Заменить фигуру в массиве по индексу" << endl;
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