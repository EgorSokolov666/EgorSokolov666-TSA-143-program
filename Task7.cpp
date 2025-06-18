#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Расчитывает сумму N членов
 * @param n Число членов последовательности
 * @return Возвращает значение суммы
 */
double sumFirstN(const int n) {

/**
 * @brief Вычисляет сумму членов последовательности, по модулю не меньших заданного числа e
 * @param e Число, которое должно быть меньше модуля члена последовательности
 * @return Возвращает значение суммы
 */
double sumModuloE(const double e);

/**
 * @brief Вычисляет рекурентное выражение
 * @param k Переменная k
 * @return (-1)^k * k!/(4+k)!
 */
double recur(const int k);

/**
 * @brief Функция для проверки ввода n
 * @return Возвращает n, если введено правильно, в противном случае -1
 */
double getValidN();

/**
 * @brief Функция для проверки ввода e
 * @return Возвращает e, если введено правильно, в противном случае -1
 */
double getValidE();

/**
*@brief Точка входа для программы
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = getValidN();

    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN(n) << endl;

    double e = getValidE();

    cout << "Сумма всех членов последовательности, модуль которых не меньше " << e << ": " << sumModuloE(e) << endl;

    return 0;
}

int getValidN()
{
    int n = 0;
    cout << "Введите значение n: ";
    cin >> n;

    if (cin.fail() || n <= 0)
    {
        cout << "Ошибка: n должно быть положительным числом." << endl;
        abort(); // Abort
    }

    return n;
}

double getValidE()
{
    double e = 0.0;
    cout << "Введите значение e: ";
    cin >> e;

    if (cin.fail() || e < numeric_limits::epsilon() ))
    {
        cout << "Ошибка: e должно быть положительным числом." << endl;
        abort(); // Abort
    }

    return e;
}

double sumFirstN(const int n)
{
    double current = -1/120;
    double sum = 0;

    for (int k = 1; k <= n; ++k)
    {
        current = recur(current, k);
        sum += current;
    }

    return sum;
}

double sumModuloE(const double e)
{
    double sum = 0;
    double current = -1/120;
    int k = 1;

    while (abs(current) >= e)
    {
        sum += current;
        current = recur(current, k);
        k++;
    }

    return sum;

}
double recur(const double current, const int k)
{
   // Recursive case: (-1)^k * k!/(4+k)! = (-1) * (-1)^(k-1) * [k/(4+k)] * (k-1)!/(4+k-1)!
    return -current * (k + 1)/ (5 + k);
}
