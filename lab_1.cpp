// Сумма элементов массива и минимальный элемент и его индекс

#include <iostream>
using namespace std;

int sumArr(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void findMin(const int arr[], int size, int &minValue, int &minIndex) {
    minValue = arr[0];
    minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }
}

int main() {
    int n;
    cout << "Размер массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка" << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "Элементы:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = sumArr(arr, n);
    cout << "Сумма: " << total << endl;

    int minVal, minIndex;
    findMin(arr, n, minVal, minIndex);

    cout << "Минимальный элемент: " << minVal << endl;
    cout << "Индекс: " << minIndex << endl;

    delete[] arr;

    return 0;
}