#include <iostream>
#include <cstdlib> // для rand() и malloc/free
#include <ctime>   // для time()
using namespace std;

// Функция для вывода массива
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция замены максимального элемента каждой строки на 0
void replaceMaxInRows(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        if (m == 0) continue;
        int maxIndex = 0;
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] > matrix[i][maxIndex]) maxIndex = j;
        }
        matrix[i][maxIndex] = 0;
    }
}

// Функция вставки строк из нулей перед строками, первый элемент которых делится на 3
int** insertZeroRows(int** matrix, int& n, int m) {
    int zeroRows = 0;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] % 3 == 0) {
            ++zeroRows;
        }
    }

    int newN = n + zeroRows;
    int** newMatrix = (int**)malloc(newN * sizeof(int*));
    if (!newMatrix) {
        cerr << "Ошибка выделения памяти для новой матрицы!" << endl;
        exit(1);
    }

    for (int i = 0; i < newN; ++i) {
        newMatrix[i] = (int*)malloc(m * sizeof(int));
        if (!newMatrix[i]) {
            cerr << "Ошибка выделения памяти для строки матрицы!" << endl;
            // Освободить ранее выделенную память
            for (int j = 0; j < i; ++j) {
                free(newMatrix[j]);
            }
            free(newMatrix);
            exit(1);
        }
    }

    int newRowIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] % 3 == 0) {
            // Вставить нулевую строку
            for (int j = 0; j < m; ++j) {
                newMatrix[newRowIndex][j] = 0;
            }
            ++newRowIndex;
        }
        // Скопировать исходную строку
        for (int j = 0; j < m; ++j) {
            newMatrix[newRowIndex][j] = matrix[i][j];
        }
        ++newRowIndex;
    }

    // Освободить память, занимаемую исходной матрицей
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    n = newN;
    return newMatrix;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(nullptr)));

    int n = 0, m = 0;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;

    // Выделение памяти для матрицы
    int** matrix = (int**)malloc(n * sizeof(int*));
    if (!matrix) {
        cerr << "Ошибка выделения памяти для матрицы!" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        if (!matrix[i]) {
            cerr << "Ошибка выделения памяти для строки матрицы!" << endl;
            // Освободить ранее выделенную память
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    // Заполнение массива случайными числами от 1 до 20
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 20 + 1;
        }
    }

    cout << "Исходный массив:\n";
    printMatrix(matrix, n, m);

    replaceMaxInRows(matrix, n, m);

    cout << "После замены максимального элемента каждой строки на 0:\n";
    printMatrix(matrix, n, m);

    matrix = insertZeroRows(matrix, n, m);

    cout << "После вставки строк из нулей перед строками, первый элемент которых делится на 3:\n";
    printMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
