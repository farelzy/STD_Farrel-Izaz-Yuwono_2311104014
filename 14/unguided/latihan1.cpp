#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahSimpul;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    string simpul[jumlahSimpul];
    int jarak[jumlahSimpul][jumlahSimpul];

    cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    cout << "Silakan masukan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " ---> " << simpul[j] << " = ";
            cin >> jarak[i][j];
        }
    }

    cout << "\n     ";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << simpul[i] << "  ";
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << simpul[i] << "    ";
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << jarak[i][j] << "    ";
        }
        cout << endl;
    }

    return 0;
}
