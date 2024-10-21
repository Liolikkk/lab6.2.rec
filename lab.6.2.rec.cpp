#include <iostream>
using namespace std;

// ������� ��� ����������� ������ ����������� ���������� (����������)
void Init(int a[], const int size, int i = 0) {
    if (i < size) {
        a[i] = rand() % 101 - 50;  // ���������� ����� ����������� ������� �� -50 �� 50
        Init(a, size, i + 1);  // ����������� ������ ��� ���������� ��������
    }
}

// ������� ��� ��������� ������ (����������)
void Print(const int a[], const int size, int i = 0) {
    if (i == 0) cout << "{";
    if (i < size) {
        cout << a[i];
        if (i != size - 1) cout << ", ";
        else cout << "}" << endl;
        Print(a, size, i + 1);  // ����������� ������ ��� ���������� ��������
    }
}

// ������� ��� ���������� ���� �������� � ��������� ��������� (����������)
int SumOddIndices(const int a[], const int size, int i = 1) {
    if (i >= size) return 0;  // ������� �������: ���� ������ �������� �� ��� ������
    return a[i] + SumOddIndices(a, size, i + 2);  // ������ ������� � ����� �� ���������� ��������� �������
}

int main() {
    srand(time(0));

    int n;
    cout << "n = "; cin >> n;  // ���������� ������� ����� ������

    int* a = new int[n];

    Init(a, n);      // ���������� ����������� ������
    Print(a, n);     // ����������� ���� ������

    int sum = SumOddIndices(a, n);  // ���������� ���������� ���� �������� � ��������� ���������
    cout << "Sum of elements with odd indices: " << sum << endl;

    delete[] a;  // ��������� ���'���
    a = nullptr;

    return 0;
}
