#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits> // для numeric_limits

using namespace std;

// Прототипы функций
double getValidDouble(const string& prompt);
double calculateY(double x);

int main() {
    double startX, endX, deltaX;

    // Ввод данных от пользователя с проверкой
    startX = getValidDouble("Введите начальное значение x (startX): ");
    endX = getValidDouble("Введите конечное значение x (endX): ");
    deltaX = getValidDouble("Введите шаг изменения x (deltaX): ");

    // Проверка корректности ввода
    if (startX >= endX || deltaX <= 0) {
        cout << "Ошибка: Некорректный ввод данных. startX должен быть меньше endX, а deltaX должен быть больше 0." << endl;
        return 1;
    }

    // Вывод заголовка таблицы
    cout << "-----------------------" << endl;
    cout << "|   x   |    y    |" << endl;
    cout << "-----------------------" << endl;

    // Табулирование функции с исправленным условием цикла
    for (double x = startX; x <= endX + deltaX/2; x += deltaX) {
        double y = calculateY(x);

        cout << fixed << setprecision(4); // Устанавливаем формат вывода

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

// Функция для безопасного ввода double значений с проверкой
double getValidDouble(const string& prompt) {
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

// Функция для вычисления значения y = 3x - 4ln(x) - 5
double calculateY(double x) {
    if (x <= 0) {
        return numeric_limits<double>::quiet_NaN(); // Возвращаем NaN, если x <= 0
    }
    return 3 * x - 4 * log(x) - 5;
}
