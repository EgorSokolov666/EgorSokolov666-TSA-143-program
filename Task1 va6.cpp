#include <iostream>
#include <cmath>
#include <limits> // для std::numeric_limits

using namespace std;

/**
 * @param x - значение переменной x
 * @param y - значение переменной y
 * @param z - значение переменной z
 * @return - возвращает рассчитанное значение
 */
double geta(const double x, const double y, const double z);

/**
 * @param x - значение переменной x
 * @param y - значение переменной y
 * @param z - значение переменной z
 * @return - возвращает рассчитанное значение
 */
double getb(const double x, const double y, const double z);

/**
 * @return - возвращает 0, если программа выполнена корректно
 */
int main() {
    const double x = 0.61;
    const double y = 3.4;
    const double z = 16.5;

    cout << "a = " << geta(x, y, z) << endl;
    cout << "b = " << getb(x, y, z) << endl;

    return 0;
}

double geta(const double x, const double y, const double z) { 
    return pow(x, 3) * pow(tan(x), 2) * pow((x + y), 2) + z / sqrt(x + y);
}

double getb(const double x, const double y, const double z) {
    double denominator = exp(z * x) - 1;
    return (y * pow(x, 2) - z) / denominator;
}
