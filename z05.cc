// PJC-C03/Z05 by Rafał Pocztarski - https://pocztarski.com/

#include <iostream>

size_t monot(const int a[], size_t size, size_t& len) {
    if ((len = size) < 3) return 0;
    size_t bo = 0, bl = 2, ro = 0, rl, mo = 0, ml;
    for (size_t i = 1; i < size + 1; i++) {
        rl = i - ro;
        ml = i - mo;
        if (i >= size || a[i]-a[i-1] < 0) {
            if (rl > bl) {
                bo = ro;
                bl = rl;
            }
            ro = i;
        }
        if (i >= size || a[i]-a[i-1] > 0) {
            if (ml > bl) {
                bo = mo;
                bl = ml;
            }
            mo = i;
        }
    }
    len = bl;
    return bo;
}

void printResult(const int a[], size_t size,
                 size_t ind, size_t len) {
    using std::cout;
    cout << "In array [ ";
    for (size_t i = 0; i < size; ++i) cout << a[i] << " ";
    cout << "]\nthe first longest "
            "monotonic sequence is\n[ ";
    for (size_t i = ind; i < ind+len; ++i)
        cout << a[i] << " ";
    cout << "] starting at index " << ind
         << " and of length " << len << "\n\n";
}

int main() {
    size_t len = 0, ind = 0, size = 0;

    int a1[] = {4,4,5,4,4};
    size = sizeof(a1)/sizeof(*a1);
    ind = monot(a1,size,len);
    printResult(a1,size,ind,len);

    int a2[] = {4,4,5,4,4,4};
    size = sizeof(a2)/sizeof(*a2);
    ind = monot(a2,size,len);
    printResult(a2,size,ind,len);

    int a3[] = {4,5,4,4,5};
    size = sizeof(a3)/sizeof(*a3);
    ind = monot(a3,size,len);
    printResult(a3,size,ind,len);
}
