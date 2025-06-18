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
void printArray(int** arr, const int rows, const int cols);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param arr Ссылка на заполняемый массив
 * @param min Нижняя граница диапазона
 * @param max Верхняя граница диапазона
 */
void fillArrayRandom(int** arr, const int rows, const int cols, const int min, const int max);

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
void fillArray(int** arr, const int rows, const int cols, const int min, const int max);

/**
 * @brief Заменяет максимальный элемент каждой строки на ноль
 * @param arr Ссылка на преобразуемый массив
 */
void replaceMaxWithZero(int** arr, const int rows, const int cols);

/**
 * @brief Вставляет строку из нулей перед строками, где первый элемент делится на 3
 * @param arr Ссылка на преобразуемый массив
 */
void insertZeroRows(int*** arr, const int rows, const int cols);

/**
 * @brief Точка входа в программу
 * @return EXIT_SUCCESS при успешном выполнении, EXIT_FAILURE при ошибке
 */
void freeArray(int** arr, const int rows);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк и столбцов массива: ";
    int rows = getSize();
    int cols = getSize();
    
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

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
        fillArrayRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        freeArray(arr, rows);
        return -1;
    }

    cout << "\nИсходный массив:\n";
    printArray(arr, rows, cols);

    replaceMaxWithZero(arr, rows, cols);
    cout << "\nМассив после замены максимальных элементов строк на нули:\n";
    printArray(arr, rows, cols);

    insertZeroRows(arr, rows, cols);
    cout << "\nМассив после вставки строк из нулей перед строками с первым элементом, делящимся на 3:\n";
    printArray(arr, rows, cols);
    
    freeArray(arr, rows);
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

void printArray(int** arr, const int rows, const int cols)
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

void fillArrayRandom(int** arr, const int rows, const int cols const int min, const int max)
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
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

void fillArray(int** arr, const int rows, const int cols, const int min, const int max)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
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

void replaceMaxWithZero(int** arr, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        int maxIndex = 0;
        for (size_t j = 1; j < cols; j++)
        {
            if (arr[i][j] > arr[i][maxIndex])
            {
                maxIndex = j;
            }
        }
        arr[i][maxIndex] = 0;
    }
}

void insertZeroRows(int*** arr, const int rows , const int cols)
{
    Сначала подсчитаем, сколько строк нужно добавить
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        if (cols > 0 && (*arr)[i][0] % 3 == 0)
        {
            count++;
        }
    }

    if (count == 0) return; // Ничего не нужно добавлять

    // Создаем новый массив с увеличенным количеством строк
    int newRows = rows + count;
    int** newArr = new int*[newRows];
    
    int newIndex = 0;
    for (int i = 0; i < rows; i++)
    {
        if (cols > 0 && (*arr)[i][0] % 3 == 0)
        {
            // Добавляем новую строку с нулями
            newArr[newIndex] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                newArr[newIndex][j] = 0;
            }
            newIndex++;
        }
        
        // Копируем текущую строку
        newArr[newIndex] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            newArr[newIndex][j] = (*arr)[i][j];
        }
        newIndex++;
    }

    // Освобождаем старый массив
    freeArray(*arr, rows);
    
    // Обновляем указатель и количество строк
    *arr = newArr;
    rows = newRows;
}

void freeArray(int** arr, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
