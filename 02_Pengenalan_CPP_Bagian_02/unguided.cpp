#include <iostream>
using namespace std;


// unguided 1
// int main() {
//     int n;
//     // Input jumlah data array
//     cout << "Masukkan jumlah elemen dalam array: ";
//     cin >> n;
//     int arr[n];
//     // Input elemen array
//     cout << "Masukkan elemen-elemen array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // Menampilkan seluruh array
//     cout << "Data Array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     // Menampilkan nomor genap
//     cout << "Nomor Genap: ";
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 == 0) {
//             cout << arr[i] << " ";
//         }
//     }
//     cout << endl;
//     // Menampilkan nomor ganjil
//     cout << "Nomor Ganjil: ";
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 != 0) {
//             cout << arr[i] << " ";
//         }
//     }
//     cout << endl;
//     return 0;
// }


// unguided 2
// int main() {
//     int x, y, z;
//     // Input ukuran array 3D
//     cout << "Masukkan ukuran x, y, z untuk array 3D: ";
//     cin >> x >> y >> z;
//     int arr[x][y][z];
//     // Input elemen array
//     cout << "Masukkan elemen-elemen array: " << endl;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             for (int k = 0; k < z; k++) {
//                 cout << "Array[" << i << "][" << j << "][" << k << "]: ";
//                 cin >> arr[i][j][k];
//             }
//         }
//     }
//     // Menampilkan array
//     cout << "Array 3D:" << endl;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             for (int k = 0; k < z; k++) {
//                 cout << arr[i][j][k] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }


int main() {
    int n;
    
    // Input jumlah elemen
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    
    int arr[n];
    
    // Input elemen array
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max = arr[0];
    int min = arr[0];
    int sum = 0;
    
    // Mencari maksimum, minimum, dan rata-rata
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }
    
    double avg = sum / (double)n;
    
    // Menampilkan hasil
    cout << "Nilai Maksimum: " << max << endl;
    cout << "Nilai Minimum: " << min << endl;
    cout << "Nilai Rata-rata: " << avg << endl;

    return 0;
}
