#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Линейный поиск
int lin(char** arr, int size, const char* key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

// Бинарный поиск
int bin(char** arr, int size, const char* key) {
    int start = 0;
    int finish = size - 1;
    
    while (start <= finish) {
        int middle = (start + finish) / 2;
        int compare = strcmp(arr[middle], key);
        
        if (compare == 0) {
            return middle;
        }
        else if (compare > 0) {
            finish = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    return -1;
}

// Вывод массива
void printArr(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << " " << arr[i] << endl;
    }
}

int main() {
    
    char** Name;
    char* tmp;
    int N, result, choice;
    
    cout << "1 - Линейный поиск" << endl;
    cout << "2 - Бинарный поиск" << endl;
    cout << "Выбор операции: ";
    cin >> choice;
    
    cout << "Количество слов: ";
    cin >> N;
    
    Name = new char*[N];
    tmp = new char[256];
    
    if (choice == 2) {
        cout << "Введите " << N << " слов в алфавитном порядке:" << endl;
    } else {
        cout << "Введите " << N << " слов:" << endl;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        Name[i] = new char[strlen(tmp) + 1];
        strcpy(Name[i], tmp);
    }
    
    cout << "\nМассив:" << endl;
    printArr(Name, N);
  
    cout << "\nИскомое слово: ";
    cin >> tmp;
    
    if (choice == 1) {
        result = lin(Name, N, tmp);
        cout << "\nЛинейный поиск" << endl;
    } else {
        result = bin(Name, N, tmp);
        cout << "\nБинарный поиск" << endl;
    }
    
    if (result == -1) {
        cout << "Нет элемента" << endl;
    } else {
        cout << "Номер элемента (счет с 0): " << result << endl;
        cout << "Номер элемента (счет с 1): " << result + 1 << endl;
    }
    
    for (int i = 0; i < N; i++) {
        delete[] Name[i];
    }
    delete[] Name;
    delete[] tmp;
    
    return 0;
}