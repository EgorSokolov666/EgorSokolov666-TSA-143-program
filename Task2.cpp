#include <iostream>
#include <cmath>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::string

using namespace std;

// Функция для получения числового ввода с проверкой на корректность
double get_valid_double(const string& prompt) {
    string input;
    double value;

    while (true) {
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
            }
        } catch (const invalid_argument& e) {
            cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
        }
    }
}

int main() {
    // Получаем координаты первой точки с проверкой ввода
    double x1 = get_valid_double("Введите координату x первой точки: ");
    double y1 = get_valid_double("Введите координату y первой точки: ");

    // Получаем координаты второй точки с проверкой ввода
    double x2 = get_valid_double("Введите координату x второй точки: ");
    double y2 = get_valid_double("Введите координату y второй точки: ");

    // Вычисляем расстояние
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Выводим результат
    cout << "Расстояние между точками (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ") равно: " << distance << endl;

    return 0;
}
