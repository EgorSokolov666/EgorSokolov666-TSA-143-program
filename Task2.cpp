#include <iostream>
#include <cmath>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::string

using namespace std;

// Функция для получения числового ввода с проверкой на корректность
double get_valid_double(const string& prompt) {
    string input;
    double value;

    cout << prompt;
    getline(cin, input); // Используем getline для чтения всей строки

    // Преобразовываем строку в double
    try {
        size_t pos;
        value = stod(input, &pos);

        // Проверяем, что вся строка была преобразована
        if (pos == input.length()) {
            return value; // Успешное преобразование
        } else {
            cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
            // Если ввод не корректный, возвращаем "бесконечность" чтобы сигнализировать об ошибке.
            return numeric_limits<double>::infinity();
        }
    } catch (const invalid_argument& e) {
        cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
        // Если ввод не корректный, возвращаем "бесконечность" чтобы сигнализировать об ошибке.
        return numeric_limits<double>::infinity();
    }
}

// Функция для вычисления расстояния между двумя точками
double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Получаем координаты первой точки с проверкой ввода
    double x1 = get_valid_double("Введите координату x первой точки: ");
    if (isinf(x1)) return 1; // Выход из программы, если ввод некорректен

    double y1 = get_valid_double("Введите координату y первой точки: ");
     if (isinf(y1)) return 1; // Выход из программы, если ввод некорректен

    // Получаем координаты второй точки с проверкой ввода
    double x2 = get_valid_double("Введите координату x второй точки: ");
     if (isinf(x2)) return 1; // Выход из программы, если ввод некорректен

    double y2 = get_valid_double("Введите координату y второй точки: ");
     if (isinf(y2)) return 1; // Выход из программы, если ввод некорректен

    // Вычисляем расстояние
    double distance = calculate_distance(x1, y1, x2, y2);

    // Выводим результат
    cout << "Расстояние между точками (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ") равно: " << distance << endl;

    return 0;
