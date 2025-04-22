#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Прототипы функций
long double sumFirstN(int n);
long double sumUntilE(double e);

int main() {
    int n;
    double e;

    // Ввод n
    cout << "Введите значение n (количество членов для суммирования): ";
    cin >> n;

    // Проверка ввода n
    if (n < 1) {
        cout << "Ошибка: Некорректный ввод для n. Введите целое число больше или равное 1." << endl;
        return 1;
    }

    // Ввод e
    cout << "Введите значение e (точность для суммирования до e): ";
    cin >> e;

    // Проверка ввода e
    if (e <= 0) {
        cout << "Ошибка: Некорректный ввод для e. Введите положительное число." << endl;
        return 1;
    }

    // Вычисление и вывод результатов
    long double sum_n = sumFirstN(n);
    long double sum_e = sumUntilE(e);

    cout << fixed << setprecision(10); // Устанавливаем точность вывода

    if (!isnan(sum_n)) {
        cout << "Сумма первых " << n << " членов: " << sum_n << endl;
    }

    if (!isnan(sum_e)) {
        cout << "Сумма членов, больших " << e << " по модулю: " << sum_e << endl;
    }

    return 0;
}

// Функция для вычисления суммы первых n членов последовательности
long double sumFirstN(int n) {
    if (n < 1) {
        cout << "Ошибка: n должно быть больше или равно 1." << endl;
        return numeric_limits<double>::quiet_NaN(); // Возвращаем NAN, если n некорректно
    }

    long double sum = 0.0;
    long double term = 0.0; // Значение текущего члена последовательности
    long double fact = 1.0; // Значение факториала
    for (int k = 1; k <= n; ++k) {
        fact *= k;  //Вычисляем факториал итеративно
        term = pow(-1, k) * fact / (4 + k);
        sum += term;
    }
    return sum;
}

// Функция для вычисления суммы всех членов последовательности,
// по модулю не меньших заданного числа e (с использованием рекуррентной формулы)
long double sumUntilE(double e) {
    if (e <= 0) {
        cout << "Ошибка: e должно быть больше 0." << endl;
        return numeric_limits<double>::quiet_NaN(); // Возвращаем NAN, если e некорректно
    }

    long double sum = 0.0;
    int k = 1;
    long double term = 1.0; // Инициализируем начальное значение для корректного вычисления по рекуррентной формуле
    long double fact = 1.0;

    while (true) {
        fact *= k;
        term = pow(-1, k) * fact / (4 + k);

        if (abs(term) < e) {
            break; // Выходим из цикла, если модуль члена меньше e
        }
        sum += term;
        k++;

        if (k > 1000) {
            cout << "Предупреждение: Сумма не сходится. Ограничение количества итераций достигнуто." << endl;
            return numeric_limits<double>::quiet_NaN();
        }
    }
    return sum;
}
