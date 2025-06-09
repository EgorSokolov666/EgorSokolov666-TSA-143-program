#include <iostream>
#include <vector>
#include <cstdlib> // для rand()
#include <ctime>   // для time()
using namespace std;

// Функция для вывода массива
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция замены максимального элемента каждой строки на 0
void replaceMaxInRows(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        if (row.empty()) continue;
        int maxIndex = 0;
        for (size_t i = 1; i < row.size(); ++i) {
            if (row[i] > row[maxIndex]) maxIndex = i;
        }
        row[maxIndex] = 0;
    }
}

// Функция вставки строк из нулей перед строками, первый элемент которых делится на 3
void insertZeroRows(vector<vector<int>>& matrix) {
    size_t cols = matrix.empty() ? 0 : matrix[0].size();
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][0] % 3 == 0) {
            vector<int> zeroRow(cols, 0);
            matrix.insert(matrix.begin() + i, zeroRow);
            ++i; // пропускаем вставленную строку
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(nullptr)));

    int n = 0 , m = 0;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Заполнение массива случайными числами от 1 до 20
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 20 + 1;
        }
    }

    cout << "Исходный массив:\n";
    printMatrix(matrix);

    replaceMaxInRows(matrix);

    cout << "После замены максимального элемента каждой строки на 0:\n";
    printMatrix(matrix);

    insertZeroRows(matrix);

    cout << "После вставки строк из нулей перед строками, первый элемент которых делится на 3:\n";
    printMatrix(matrix);

    return 0;
}
