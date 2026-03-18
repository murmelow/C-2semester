// Список без повторений + рейтинг + подсчет суммарной характеристики

#include <iostream>
#include <cstring>

using namespace std;

int spisok(char** name, int n, int* ch, char** list, int* rate, int* sum) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        int l = -1;
        for (int j = 0; j < k; j++) {
            if (strcmp(name[i], list[j]) == 0) {
                l = j;
                break;
            }
        }

        if (l == -1) {
            list[k] = new char[strlen(name[i]) + 1];
            strcpy(list[k], name[i]);

            rate[k] = 1;
            sum[k] = ch[i];

            k++;
        }
        else {
            rate[l]++;
            sum[l] += ch[i];
        }
    }

    return k;
}

int main() {
    int N;
    
    cout << "Размер: ";
    cin >> N;

    char** name = new char*[N];
    char** list = new char*[N];

    int* ch = new int[N];
    int* rate = new int[N];
    int* sum = new int[N];

    char tmp[256];

    cout << "Имя: ";
    for (int i = 0; i < N; i++) {
        cin >> tmp >> ch[i];

        name[i] = new char[strlen(tmp) + 1];
        strcpy(name[i], tmp);
    }

    int k = spisok(name, N, ch, list, rate, sum);

    cout << "\nСписок без повторов: ";
    for (int i = 0; i < k; i++)
    {
        cout << "[" << i << "] = " << list[i]
             << "  Рейтинг: " << rate[i]
             << "  Сумма: " << sum[i] << endl;
    }

    return 0;
}