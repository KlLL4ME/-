#include <iostream>
#include <string>
using namespace std;

void generateBinaryStrings(int n, string current = "") {
    // Базовый случай
    if (current.length() == n) {
        cout << current << endl;
        return;
    }
    // Рекурсивный случай: добавляем '0' или '1'
    generateBinaryStrings(n, current + "0");
    generateBinaryStrings(n, current + "1");
}

int main() {
    int n = 3;
    cout << "Все бинарные строки длины " << n << ":" << endl;
    generateBinaryStrings(n);
    return 0;
}
