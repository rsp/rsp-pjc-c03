// PJC-C03/Z01 by Rafał Pocztarski - https://pocztarski.com/

#include <iostream>
#include <utility>

void getMinMax(double *a, double* b, double* c,
               double** ptrMin, double** ptrMax);

void getMinMax(double &a, double& b, double& c,
               double*& ptrMin, double*& ptrMax) {
    getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
}

void getMinMax(double *a, double* b, double* c,
               double** ptrMin, double** ptrMax) {
    *ptrMin = *a < *b ? (*a < *c ? a : c) : (*b < *c ? b : c);
    *ptrMax = *a > *b ? (*a > *c ? a : c) : (*b > *c ? b : c);
}

void ord3(double* a, double* b, double* c);

void ord3(double& a, double& b, double& c) {
    ord3(&a, &b, &c);
}

void ord3(double* a, double* b, double* c) {
    using std::swap;
    if (*a > *b) swap(*a, *b);
    if (*a > *c) swap(*a, *c);
    if (*b > *c) swap(*b, *c);
}

int main() {
    using std::cout; using std::endl;
    double a, b, c, *ptrMin, *ptrMax;

    a = 2; b = 1; c = 3;
    ord3(a, b, c);
    cout << a << " " << b << " " << c << endl;

    a = 3; b = 2; c = 1;
    ord3(&a, &b, &c);
    cout << a << " " << b << " " << c << endl;

    a = 2; b = 3; c = 1;
    getMinMax(a, b, c, ptrMin, ptrMax);
    std:: cout << "Min = " << *ptrMin << "; "
               << "Max = " << *ptrMax << std::endl;

    a = 3; b = 1; c = 2;
    getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
    std:: cout << "Min = " << *ptrMin << "; "
               << "Max = " << *ptrMax << std::endl;
}
