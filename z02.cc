// PJC-C03/Z05 by Rafał Pocztarski - https://pocztarski.com/

#include <iostream>
#include <cstring>

// ...
bool digits(const char* p) {
    for (; *p; p++)
        if ('0' <= *p && *p <= '9')
            return true;
    return false;
}

bool uppercase(const char* p) {
    for (; *p; p++)
        if ('A' <= *p && *p <= 'Z')
            return true;
    return false;
}

bool lowercase(const char* p) {
    for (; *p; p++)
        if ('a' <= *p && *p <= 'z')
            return true;
    return false;
}

bool nonalpha(const char* p) {
    for (; *p; p++)
        if ( !('A' <= *p && *p <= 'Z') &&
             !('a' <= *p && *p <= 'z') &&
             !('0' <= *p && *p <= '9') )
                return true;
    return false;
}

int distinct(const char* p) {
    int c[128] = {0}, r = 0;
    for (; *p; p++) c[(int)*p]++;
    for (int i = 0; i < 128; i++)
        if (c[i]) r++;
    return r;
}

bool checkpass(const char* pass) {
    using std::cout; using std::endl;
    bool r = true;
    if (std::strlen(pass) < 8) {
        cout << "Powinno byc co najmniej 8 znakow" << endl;
        r = false;
    }
    if (distinct(pass) < 6) {
        cout << "Powinno byc co najmniej 6 znakow roznych!" << endl;
        r = false;
    }
    if (!digits(pass)) {
        cout << "Powinna byc co najmniej 1 cyfra!" << endl;
        r = false;
    }
    if (!uppercase(pass)) {
        cout << "Powinna byc co najmniej 1 duza litera!" << endl;
        r = false;
    }
    if (!lowercase(pass)) {
        cout << "Powinna byc co najmniej 1 mala litera!" << endl;
        r = false;
    }
    if (!nonalpha(pass)) {
        cout << "Powinna byc co najmniej 1 znak niealfanumeryczny!" << endl;
        r = false;
    }
    return r;
}

int main() {
    using std::cout; using std::endl;
    const char* passes[] =
        {
            "AbcDe93",  "A1b:A1b>",  "Ab:Acb<",
            "abc123><", "Zorro@123", nullptr
        };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}
