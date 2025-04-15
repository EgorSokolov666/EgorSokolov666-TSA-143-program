#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления факториала (не рекурсивная)
long double factorial(int n) {
    if (n == 0) {
        return 1.0;
    }
    long double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// a) Функция для вычисления суммы первых n членов последовательности
long double sumFirstN(int n) {
    if (n < 1) {
        cout << "Ошибка: n должно быть больше или равно 1." << endl;
        return NAN; // Возвращаем NAN, если n некорректно
    }

    long double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        sum += pow(-1, k) * factorial(k) / (4 + k);
    }
    return sum;
}

// b) Функция для вычисления суммы всех членов последовательности,
//    по модулю не меньших заданного числа e
long double sumUntilE(double e) {
    if (e <= 0) {
        cout << "Ошибка: e должно быть больше 0." << endl;
        return NAN; // Возвращаем NAN, если e некорректно
    }

    long double sum = 0.0;
    int k = 1;
    long double term;

    while (true) {
        term = pow(-1, k) * factorial(k) / (4 + k);
        if (abs(term) < e) {
            break; // Выходим из цикла, если модуль члена меньше e
        }
        sum += term;
        k++;
        if (k > 1000) {
          cout << "Предупреждение:  Сумма не сходится.  Ограничение количества итераций достигнуто." << endl;
          return NAN;
        }

    }
    return sum;
}

int main() {
    int n;
    double e;

    // Ввод n
    cout << "Введите значение n (количество членов для суммирования): ";
    cin >> n;

    // Проверка ввода n
    if (cin.fail() || n < 1) {
        cout << "Ошибка: Некорректный ввод для n. Введите целое число больше или равное 1." << endl;
        return 1;
    }

    // Ввод e
    cout << "Введите значение e (точность для суммирования до e): ";
    cin >> e;

    // Проверка ввода e
    if (cin.fail() || e <= 0) {
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