// PJC-C03/Z03 by Rafał Pocztarski - https://pocztarski.com/

#include <iostream>

size_t strlen(const char *a) {
    size_t i = 0;
    char *s = (char *)a;
    while (*(s++)) i++;
    return i;
}

int sim(const char a[], const char b[], size_t s) {
    int t = 0, c = 0;
    for (size_t i = 0; i <= s; i++) {
        if (i >= s || a[i] != b[i]) {
            t += c*c;
            c = 0;
        } else {
            c++;
        }
    }
    return t;
}

int simil(const char a[], const char b[]) {
    size_t al = strlen(a), bl = strlen(b);
    const char *x = (al < bl ? b : a), *y = (al < bl ? a : b);
    size_t xl = (al < bl ? bl : al), yl = (al < bl ? al : bl);
    int pm = 0, pc = 0;
    for (size_t o = 0; o <= xl-yl; o++) {
        pc = sim(x+o, y, yl);
        if (pc > pm) pm = pc;
    }
    return pm;
}

int main() {
    char a[] = "AACTACGTC",
         b[] = "ACGTA";
    std::cout << a << " and " << b << " -> "
              << simil(a,b) << std::endl;
    char c[] = "GCGC",
         d[] = "AGGGCA";
    std::cout << c << " and " << d << " -> "
              << simil(c,d) << std::endl;
}
