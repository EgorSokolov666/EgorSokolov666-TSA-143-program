#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Прототипы функций
long double sumFirstN(int n, int k = 1, long double term = -1.0/5.0, long double sum = 0.0);
long double sumUntilE(double e, int k = 1, long double term = -1.0/5.0, long double sum = 0.0);
bool getValidInt(int& value, const string& prompt);
bool getValidDouble(double& value, const string& prompt);

int main() {
    int n = 0;
    double e = 0.0;

    // Ввод n с проверкой (рекурсивный)
    if (!getValidInt(n, "Введите значение n (количество членов для суммирования, целое число >= 1): ")) {
        return 1;
    }

    // Ввод e с проверкой (рекурсивный)
    if (!getValidDouble(e, "Введите значение e (точность для суммирования до e, положительное число): ")) {
        return 1;
    }

    // Вычисление и вывод результатов
    long double sum_n = sumFirstN(n);
    long double sum_e = sumUntilE(e);

    cout << fixed << setprecision(10);

    if (!isnan(sum_n)) {
        cout << "Сумма первых " << n << " членов: " << sum_n << endl;
    }

    if (!isnan(sum_e)) {
        cout << "Сумма членов, больших " << e << " по модулю: " << sum_e << endl;
    }

    return 0;
}

// Рекурсивная функция для ввода целого числа с проверкой
bool getValidInt(int& value, const string& prompt) {
    cout << prompt;
    if (!(cin >> value) || value < 1) {
        cout << "Ошибка: Некорректный ввод. Пожалуйста, введите целое число больше или равное 1." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getValidInt(value, prompt); // Рекурсивный вызов
    }
    return true;
}

// Рекурсивная функция для ввода дробного числа с проверкой
bool getValidDouble(double& value, const string& prompt) {
    cout << prompt;
    if (!(cin >> value) || value <= 0) {
        cout << "Ошибка: Некорректный ввод. Пожалуйста, введите положительное число." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getValidDouble(value, prompt); // Рекурсивный вызов
    }
    return true;
}

// Рекурсивная функция для вычисления суммы первых n членов последовательности
long double sumFirstN(int n, int k, long double term, long double sum) {
    if (n < 1) {
        cout << "Ошибка: n должно быть больше или равно 1." << endl;
        return numeric_limits<double>::quiet_NaN();
    }

    sum += term;
    
    if (k >= n) {
        return sum;
    }
    
    long double next_term = term * (-(k+1)) / (4.0 + (k+1));
    return sumFirstN(n, k+1, next_term, sum);
}

// Рекурсивная функция для вычисления суммы членов, больших e по модулю
long double sumUntilE(double e, int k, long double term, long double sum) {
    if (e <= 0) {
        cout << "Ошибка: e должно быть больше 0." << endl;
        return numeric_limits<double>::quiet_NaN();
    }

    if (abs(term) < e) {
        return sum;
    }
    
    if (k > 1000) {
        cout << "Предупреждение: Сумма не сходится. Ограничение количества итераций достигнуто." << endl;
        return numeric_limits<double>::quiet_NaN();
    }
    
    long double next_term = term * (-(k+1)) / (4.0 + (k+1));
    return sumUntilE(e, k+1, next_term, sum + term);
}
