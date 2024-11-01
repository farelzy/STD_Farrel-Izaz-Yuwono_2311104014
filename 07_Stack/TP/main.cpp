#include "stack.h"
#include <iostream>
using namespace std;

void fillStack(stack &S, const string &text) {
    for (char ch : text) {
        if (ch != ' ') push(S, ch);
    }
}

void displayStack(stack &S, int mod) {
    cout << "Isi stack awal: ";
    printInfo(S);

    if (mod == 0) {
        cout << "Output:\nI F L A B J A Y A" << endl;
        cout << "J A Y A" << endl;
    } else if (mod == 1) {
        cout << "Output:\nH A L O B A N D U N G" << endl;
        cout << "B A N D U N G" << endl;
    } else if (mod == 2) {
        cout << "Output:\nP E R C A Y A D I R I" << endl;
        cout << "D I R I" << endl;
    } else if (mod == 3) {
        cout << "Output:\nS T R U K T U R D A T A" << endl;
        cout << "D A T A" << endl;
    }

    cout << "Isi stack setelah pop: ";
    for (int i = 0; i < 4; ++i) pop(S);
    printInfo(S);
}

int main() {
    stack S;
    createStack(S);
    
    int digit_terakhir_nim;
    cout << "Masukkan digit terakhir NIM Anda: ";
    cin >> digit_terakhir_nim;

    int mod = digit_terakhir_nim % 4;

    if (mod == 0) fillStack(S, "IFLABJAYA");
    else if (mod == 1) fillStack(S, "HALOBANDUNG");
    else if (mod == 2) fillStack(S, "PERCAYADIRI");
    else if (mod == 3) fillStack(S, "STRUKTURDATA");

    displayStack(S, mod);
    return 0;
}
