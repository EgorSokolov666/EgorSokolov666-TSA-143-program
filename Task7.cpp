#include <iostream>
#include <vector>
#include <random>
#include <limits> // Для numeric_limits

using namespace std;

// Функция для создания матрицы
vector<vector<int>> createMatrix(int rows, int cols, bool randomFill) {
    vector<vector<int>> matrix(rows, vector<int>(cols));

    if (randomFill) {
        // Заполнение случайными числами от -10 до 10
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(-10, 10);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = distrib(gen);
            }
        }
    } else {
        // Заполнение с клавиатуры
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Элемент [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    return matrix;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 1. Заменить максимальный элемент каждой строки нулем.
void replaceMaxWithZero(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        int maxVal = numeric_limits<int>::min();  // Инициализируем минимальным возможным значением int
        int maxIndex = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxIndex = j;
            }
        }
        matrix[i][maxIndex] = 0;
    }
}

// 2. Вставить перед всеми строками, первый элемент которых делится на 3, строку из нулей.
void insertZeroRows(vector<vector<int>>& matrix) {
    vector<vector<int>> newMatrix;
    int cols = matrix[0].size();  // Количество столбцов в матрице

    for (int i = 0; i < matrix.size(); ++i) {
        if (!matrix[i].empty() && matrix[i][0] % 3 == 0) {
            // Вставляем строку из нулей
            newMatrix.push_back(vector<int>(cols, 0));
        }
        newMatrix.push_back(matrix[i]);
    }

    matrix = newMatrix; // Обновляем матрицу
}

int main() {
    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> cols;

    char fillChoice;
    cout << "Заполнить случайными числами? (y/n): ";
    cin >> fillChoice;

    bool randomFill = (fillChoice == 'y' || fillChoice == 'Y');

    vector<vector<int>> matrix = createMatrix(rows, cols, randomFill);

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    replaceMaxWithZero(matrix);
    cout << "Матрица после замены максимальных элементов каждой строки на нуль:" << endl;
    printMatrix(matrix);

    insertZeroRows(matrix);
    cout << "Матрица после вставки строки нулей перед строками, где первый элемент делится на 3:" << endl;
    printMatrix(matrix);

    return 0;
}
