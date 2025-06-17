#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @enum SELECT
 * @brief Перечисление для выбора способа заполнения массива
 */
enum SELECT
{
    RANDOM = 0,    ///< Автоматическое заполнение случайными числами
    MANUALLY = 1   ///< Ручное заполнение с клавиатуры
};

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемый размер
 * @throw std::invalid_argument Если размер некорректен (n <= 0)
 */
void checkN(const int n);

/**
 * @brief Получает от пользователя размер массива
 * @return Размер массива в беззнаковом типе
 */
size_t getSize();

/**
 * @brief Считывает целое число с клавиатуры
 * @return Введенное число
 * @throw std::runtime_error При ошибке ввода
 */
int getNumber();

/**
 * @brief Выводит двумерный массив на экран
 * @param arr Константная ссылка на выводимый массив
 */
void printArray(const vector<vector<int>>& arr);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param arr Ссылка на заполняемый массив
 * @param min Нижняя граница диапазона
 * @param max Верхняя граница диапазона
 */
void fillArrayRandom(vector<vector<int>>& arr, const int min, const int max);

/**
 * @brief Проверяет корректность диапазона значений
 * @param min Нижняя граница диапазона
 * @param max Верхняя граница диапазона
 * @throw std::invalid_argument Если min > max
 */
void checkRange(const int min, const int max);

/**
 * @brief Заполняет массив вручную с клавиатуры
 * @param arr Ссылка на заполняемый массив
 * @param min Нижняя граница допустимых значений
 * @param max Верхняя граница допустимых значений
 */
void fillArray(vector<vector<int>>& arr, const int min, const int max);

/**
 * @brief Заменяет максимальный элемент каждой строки на ноль
 * @param arr Ссылка на преобразуемый массив
 */
void replaceMaxWithZero(vector<vector<int>>& arr);

/**
 * @brief Вставляет строку из нулей перед строками, где первый элемент делится на 3
 * @param arr Ссылка на преобразуемый массив
 */
void insertZeroRows(vector<vector<int>>& arr);

/**
 * @brief Точка входа в программу
 * @return EXIT_SUCCESS при успешном выполнении, EXIT_FAILURE при ошибке
 */

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк и столбцов массива: ";
    int rows = getSize();
    int cols = getSize();
    
    vector<vector<int>> arr(rows, vector<int>(cols));

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " - Для случайного заполнения" << endl
        << MANUALLY << " - Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return -1;
    }

    cout << "\nИсходный массив:\n";
    printArray(arr);

    replaceMaxWithZero(arr);
    cout << "\nМассив после замены максимальных элементов строк на нули:\n";
    printArray(arr);

    insertZeroRows(arr);
    cout << "\nМассив после вставки строк из нулей перед строками с первым элементом, делящимся на 3:\n";
    printArray(arr);

    return EXIT_SUCCESS;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        throw invalid_argument("Размер массива должен быть положительным числом");
    }
}

size_t getSize()
{
    int n = 0;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        cerr << "Неправильный ввод данных" << endl;
        abort();
    }
    return number;
}

void printArray(const vector<vector<int>>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void fillArrayRandom(vector<vector<int>>& arr, const int min, const int max)
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr[i].size(); j++)
        {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cerr << "Введен неправильный диапазон" << endl;
        abort();
    }
}

void fillArray(vector<vector<int>>& arr, const int min, const int max)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr[i].size(); j++)
        {
            cout << "Введите значение для arr[" << i << "][" << j << "]: ";
            arr[i][j] = getNumber();

            while (arr[i][j] < min || arr[i][j] > max)
            {
                cout << "Значение вне диапазона [" << min << ", " << max << "]. Повторите ввод: ";
                arr[i][j] = getNumber();
            }
        }
    }
}

void replaceMaxWithZero(vector<vector<int>>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        int maxIndex = 0;
        for (size_t j = 1; j < arr[i].size(); j++)
        {
            if (arr[i][j] > arr[i][maxIndex])
            {
                maxIndex = j;
            }
        }
        arr[i][maxIndex] = 0;
    }
}

void insertZeroRows(vector<vector<int>>& arr)
{
    vector<vector<int>> newArr;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i].size() > 0 && arr[i][0] % 3 == 0)
        {
            newArr.push_back(vector<int>(arr[i].size(), 0));
        }r.push_back(arr[i]);
    }
    arr = newArr;
} newAr
