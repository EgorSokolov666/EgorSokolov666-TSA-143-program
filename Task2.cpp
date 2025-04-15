#include <iostream>
#include <cmath>
#include <limits> // Для std::numeric_limits

using namespace std;

// Функция для проверки ввода на число
bool is_number(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0 && c != '.' && c != '-') return false; // Разрешаем цифры, точку и минус
    }
    return true;
}

// Функция для получения числового ввода с проверкой на корректность
double get_valid_double(const string& prompt) {
    string input;
    double value;

    while (true) {
        cout << prompt;
        getline(cin, input); // Используем getline для чтения всей строки (включая пробелы)

        if (is_number(input)) {
            try {
                value = stod(input); // Преобразуем строку в double
                return value;
            } catch (const std::invalid_argument& e) {
                cout << "Ошибка: Не удалось преобразовать ввод в число.  Пожалуйста, введите число." << endl;
            } catch (const std::out_of_range& e) {
                cout << "Ошибка: Введенное число слишком большое или слишком маленькое.  Пожалуйста, введите число в допустимом диапазоне." << endl;
            }
        } else {
            cout << "Ошибка: Ввод содержит недопустимые символы. Пожалуйста, введите только числа, точку или минус." << endl;
        }
    }
}


int main() {
    double x1, y1, x2, y2;

    cout << "Вычисление расстояния между двумя точками." << endl;

    // Получаем координаты первой точки с проверкой ввода
    x1 = get_valid_double("Введите координату x первой точки: ");
    y1 = get_valid_double("Введите координату y первой точки: ");

    // Получаем координаты второй точки с проверкой ввода
    x2 = get_valid_double("Введите координату x второй точки: ");
    y2 = get_valid_double("Введите координату y второй точки: ");

    // Вычисляем расстояние
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Выводим результат
    cout << "Расстояние между точками (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ") равно: " << distance << endl;

    return 0;
}