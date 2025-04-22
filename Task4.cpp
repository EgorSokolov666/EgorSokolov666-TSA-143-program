#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits> // для numeric_limits

using namespace std;

// Прототипы функций (объявление без реализации)
double getValue(const string& prompt);
double calculateY(double x);

int main() {
    double X1, X2, deltaX;

    // Ввод данных от пользователя с использованием getValue()
    X1 = getValue("Введите начальное значение x (X1): ");
    X2 = getValue("Введите конечное значение x (X2): ");
    deltaX = getValue("Введите шаг изменения x (deltaX): ");

    // Проверка корректности ввода
    if (X1 >= X2 || deltaX <= 0) {
        cout << "Ошибка: Некорректный ввод данных. X1 должен быть меньше X2, а deytaX должен быть больше 0." << endl;
        return 1;
    }

    // Вывод заголовка таблицы
    cout << "-----------------------" << endl;
    cout << "|   x   |    y    |" << endl;
    cout << "-----------------------" << endl;

    // Табулирование функции (исправлено условие цикла)
    for (double x = X1; x <= X2 + deltaX; x += deltaX) {
        double y = calculateY(x);

        cout << fixed << setprecision(4); // Устанавливаем формат вывода для чисел с плавающей точкой

        cout << "| " << setw(5) << x << " | ";

        if (isnan(y)) {
            cout << "  N/A   |" << endl; // Выводим "N/A", если значение y не определено
        } else {
            cout << setw(7) << y << " |" << endl;
        }
    }

    cout << "-----------------------" << endl;

    return 0;
}

// Функция для безопасного ввода значений с проверкой (реализация)
double getValue(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Пожалуйста, введите числовое значение." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Функция для вычисления значения функции y = 3x - 4ln(x) - 5 (реализация)
double calculateY(double x) {
    if (x <= 0) {
        return numeric_limits<double>::quiet_NaN(); // Возвращаем NaN, если x <= 0 (логарифм не определен)
    }
    return 3 * x - 4 * log(x) - 5;
}  
