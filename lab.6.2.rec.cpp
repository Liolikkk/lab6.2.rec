#include <iostream>
using namespace std;

// Функція для ініціалізації масиву випадковими значеннями (рекурсивно)
void Init(int a[], const int size, int i = 0) {
    if (i < size) {
        a[i] = rand() % 101 - 50;  // Заповнюємо масив випадковими числами від -50 до 50
        Init(a, size, i + 1);  // Рекурсивний виклик для наступного елемента
    }
}

// Функція для виведення масиву (рекурсивно)
void Print(const int a[], const int size, int i = 0) {
    if (i == 0) cout << "{";
    if (i < size) {
        cout << a[i];
        if (i != size - 1) cout << ", ";
        else cout << "}" << endl;
        Print(a, size, i + 1);  // Рекурсивний виклик для наступного елемента
    }
}

// Функція для обчислення суми елементів з непарними індексами (рекурсивно)
int SumOddIndices(const int a[], const int size, int i = 1) {
    if (i >= size) return 0;  // Базовий випадок: якщо індекс виходить за межі масиву
    return a[i] + SumOddIndices(a, size, i + 2);  // Додаємо елемент і йдемо до наступного непарного індексу
}

int main() {
    srand(time(0));

    int n;
    cout << "n = "; cin >> n;  // Користувач вводить розмір масиву

    int* a = new int[n];

    Init(a, n);      // Рекурсивна ініціалізація масиву
    Print(a, n);     // Рекурсивний вивід масиву

    int sum = SumOddIndices(a, n);  // Рекурсивне обчислення суми елементів з непарними індексами
    cout << "Sum of elements with odd indices: " << sum << endl;

    delete[] a;  // Звільняємо пам'ять
    a = nullptr;

    return 0;
}
