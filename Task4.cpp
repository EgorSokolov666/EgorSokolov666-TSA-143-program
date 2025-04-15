#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits> // для numeric_limits

using namespace std;

// Функция для вычисления значения функции y = 3x - 4ln(x) - 5
double calculateY(double x) {
    if (x <= 0) {
        return numeric_limits<double>::quiet_NaN(); // Возвращаем NaN, если x <= 0 (логарифм не определен)
    }
    return 3 * x - 4 * log(x) - 5;
}

int main() {
    double startX, endX, deltaX;

    // Ввод данных от пользователя
    cout << "Введите начальное значение x (startX): ";
    cin >> startX;
    cout << "Введите конечное значение x (endX): ";
    cin >> endX;
    cout << "Введите шаг изменения x (deltaX): ";
    cin >> deltaX;

    // Проверка корректности ввода
    if (startX >= endX || deltaX <= 0) {
        cout << "Ошибка: Некорректный ввод данных. startX должен быть меньше endX, а deltaX должен быть больше 0." << endl;
        return 1;
    }

    // Вывод заголовка таблицы
    cout << "-----------------------" << endl;
    cout << "|   x   |    y    |" << endl;
    cout << "-----------------------" << endl;

    // Табулирование функции
    for (double x = startX; x <= endX; x += deltaX) {
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