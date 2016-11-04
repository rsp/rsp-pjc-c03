// PJC-C03/Z04 by Rafał Pocztarski - https://pocztarski.com/

#include <iostream>
using namespace std;

int max(int a[], size_t s) {
    if (s < 1) return 0;
    int m = a[0];
    for (size_t i = 1; i < s; i++)
        if (a[i] > m) m = a[i];
    return m;
}

void histo(int a[], size_t s) {
    while (int m = max(a, s)) {
        for (size_t i = 0; i < s; i++)
            cout << (a[i] == m ? --a[i], '*' : ' ');
        cout << endl;
    }
}

int main() {
    int arr[]{2,1,0,7,1,9};
    size_t size = sizeof(arr) / sizeof(*arr);
    histo(arr, size);
}
