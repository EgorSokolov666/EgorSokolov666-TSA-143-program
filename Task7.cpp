#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введённое значение
 */
double getValue();

/**
 * @brief Проверяет, расположены ли три точки на одной прямой
 * @param x1, y1 - координаты точки A
 * @param x2, y2 - координаты точки B
 * @param x3, y3 - координаты точки C
 * @return true, если точки на одной прямой, иначе false
 */
bool areCollinear(double x1, double y1, double x2, double y2, double x3, double y3);

/**
 * @brief Вычисляет угол B в градусах между AB и BC
 * @param x1, y1 - координаты точки A
 * @param x2, y2 - координаты точки B
 * @param x3, y3 - координаты точки C
 * @return Угол B в градусах
 */
double calculateAngleB(double x1, double y1, double x2, double y2, double x3, double y3);

/**
 * @brief Проверяет значение на корректность (больше нуля)
 * @param value - проверяемое значение
 */
void checkValue(double value);

/**
 * @brief Главная функция программы, определяющая коллинеарность трех точек и, если необходимо, вычисляющая угол между ними.
 *
 * Функция main выполняет следующие действия:
 * 1. Устанавливает локаль для корректного отображения русских символов.
 * 2. Запрашивает у пользователя координаты трех точек A, B и C, используя функцию getValue.
 * 3. Проверяет, расположены ли точки на одной прямой, вызывая функцию areCollinear.
 * 4. Если точки коллинеарны, выводит соответствующее сообщение.
 * 5. Если точки не коллинеарны:
 *    - Вызывает функцию calculateAngleB для вычисления угла B между векторами BA и BC.
 *    - Если calculateAngleB возвращает NAN (Not a Number), то это означает, что точки B, A и/или С совпадают и угол не определен. В этом случае выводится сообщение об ошибке.
 *    - В противном случае выводится значение угла B в градусах.
 *
 * @return 0 Код возврата, сигнализирующий об успешном завершении программы.
 */
int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::cout << "Введите координаты точки A (x1, y1): " << std::endl;
    double x1 = getValue();
    double y1 = getValue();

    std::cout << "Введите координаты точки B (x2, y2): " << std::endl;
    double x2 = getValue();
    double y2 = getValue();

    std::cout << "Введите координаты точки C (x3, y3): " << std::endl;
    double x3 = getValue();
    double y3 = getValue();

    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        std::cout << "Точки A, B и C расположены на одной прямой." << std::endl;
    } else {
        double angleB = calculateAngleB(x1, y1, x2, y2, x3, y3);
        if (std::isnan(angleB)) {
            // Обработка случая, когда угол не определен (совпадение точек)
            std::cout << "Невозможно вычислить угол, точки совпадают." << std::endl;
        } else {
            std::cout << "Точки A, B и C не расположены на одной прямой." << std::endl;
            std::cout << "Угол B: " << angleB << " градусов." << std::endl;
        }
    }

    return 0;
}

double getValue() {
    double value;
    cin >> value;
    checkValue(value);
    return value;
}

 bool areCollinear(double x1, double y1, double x2, double y2, double x3, double y3) {
      const double epsilon = 1e-6; // Задайте небольшое значение для погрешности
      return std::fabs((y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1)) < epsilon;
    };
}

double calculateAngleB(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Вектор AB
    double ABx = x2 - x1;
    double ABy = y2 - y1;

    // Вектор BC
    double BCx = x3 - x2;
    double BCy = y3 - y2;

    // Вычисление угла между векторами AB и BC
    double dotProduct = ABx * BCx + ABy * BCy;
    double magnitudeAB = sqrt(ABx * ABx + ABy * ABy);
    double magnitudeBC = sqrt(BCx * BCx + BCy * BCy);

    // Угол в радианах
    double angleRadian = acos(dotProduct / (magnitudeAB * magnitudeBC));

    // Перевод угла в градусы
    return angleRadian * (180.0 / PI);
}

void checkValue(double value) {
    if (cin.fail() || value <= 0) {
        cout << "Ошибка: введено некорректное значение." << endl;
        cin.clear(); // Сбрасываем состояние потока
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
        abort();
    }
}
