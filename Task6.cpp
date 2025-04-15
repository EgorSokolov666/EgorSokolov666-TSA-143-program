#include <iostream>
#include <vector>
#include <random>
#include <algorithm>  // Для reverse

using namespace std;

// Функция для создания массива
vector<int> createArray(int n, bool randomFill) {
    vector<int> arr(n);

    if (randomFill) {
        // Заполнение случайными числами от -1000 до 1000
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(-1000, 1000);

        for (int i = 0; i < n; ++i) {
            arr[i] = distrib(gen);
        }
    } else {
        // Заполнение с клавиатуры
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Элемент [" << i << "]: ";
            cin >> arr[i];
        }
    }

    return arr;
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// 1. Найти сумму отрицательных элементов, значения которых кратно 10.
int sumNegativeMultiplesOfTen(const vector<int>& arr) {
    int sum = 0;
    for (int val : arr) {
        if (val < 0 && val % 10 == 0) {
            sum += val;
        }
    }
    return sum;
}

// 2. Заменить первые k элементов массива на те же элементы в обратном порядке.
void reverseFirstK(vector<int>& arr, int k) {
    if (k > 0 && k <= arr.size()) {
        reverse(arr.begin(), arr.begin() + k);
    } else {
        cout << "Некорректное значение k. Операция не выполнена." << endl;
    }
}

// 3. Определить, есть ли пара соседних элементов с произведением, равным заданному числу.
bool hasAdjacentPairWithProduct(const vector<int>& arr, int targetProduct) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] * arr[i + 1] == targetProduct) {
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    char fillChoice;
    cout << "Заполнить случайными числами? (y/n): ";
    cin >> fillChoice;

    bool randomFill = (fillChoice == 'y' || fillChoice == 'Y');

    vector<int> arr = createArray(n, randomFill);

    cout << "Исходный массив:" << endl;
    printArray(arr);

    // Выполнение задач
    int sum = sumNegativeMultiplesOfTen(arr);
    cout << "Сумма отрицательных элементов, кратных 10: " << sum << endl;

    int k;
    cout << "Введите значение k (количество элементов для разворота): ";
    cin >> k;
    reverseFirstK(arr, k);
    cout << "Массив после разворота первых " << k << " элементов:" << endl;
    printArray(arr);

    int targetProduct;
    cout << "Введите целевое произведение для поиска пары соседних элементов: ";
    cin >> targetProduct;
    if (hasAdjacentPairWithProduct(arr, targetProduct)) {
        cout << "В массиве есть пара соседних элементов с произведением, равным " << targetProduct << endl;
    } else {
        cout << "В массиве нет пары соседних элементов с произведением, равным " << targetProduct << endl;
    }

    return 0;
}