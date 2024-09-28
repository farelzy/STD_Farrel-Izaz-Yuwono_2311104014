#include <iostream>
using namespace std;
//NO 1
// float data1, data2;
// cout << "Enter first number: ";
// cin >> data1;
// cout << "Enter second number: ";
// cin >> data2;
// cout << "Hasil Jumlah: " << data1 + data2 << endl;
// cout << "Hasil Kurang: " << data1 - data2 << endl;
// cout << "Hasil Kali: " << data1 * data2 << endl;
// cout << "Hasil Bagi: " << data1 / data2 << endl;
// return 0;


//N0 2
// string teks(int angka)
// {
//     string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
//     string belasan[] = {"", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
//     string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
//     if (angka == 0)
//         return "nol";
//     else if (angka == 100)
//         return "seratus";
//     else if (angka < 10)
//         return satuan[angka];
//     else if (angka < 20)
//         return belasan[angka - 10];
//     else
//     {
//         string teks = puluhan[angka / 10];
//         if (angka % 10 != 0)
//             teks += " " + satuan[angka % 10];
//         return teks;
//     }
// }
//     int main()
//     {
//         int angka;
//         cout << "Masukkan angka (0-100): ";
//         cin >> angka;
//         cout << angka << " : " << teks(angka) << endl;
//         return 0;
//     }


// N0 3
int main()
{
    int input;
    cout << "Masukkan angka: ";
    cin >> input;

    for (int i = input; i >= 1; i--)
    {
        // Bagian kiri
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        // Bintang di tengah
        cout << "* ";

        // Bagian kanan
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // Ganti baris
        cout << endl;
    }

    // Baris terakhir dengan hanya "*"
    cout << " * " << endl;

    return 0;
}