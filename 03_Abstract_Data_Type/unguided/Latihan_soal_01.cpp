#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Fungsi untuk input data mahasiswa
void inputMahasiswa(Mahasiswa &mhs) {
    cout << "Masukkan nama: ";
    cin >> mhs.nama;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan nilai UTS: ";
    cin >> mhs.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> mhs.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> mhs.tugas;
    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilMahasiswa(Mahasiswa mhs) {
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "Nilai UTS: " << mhs.uts << endl;
    cout << "Nilai UAS: " << mhs.uas << endl;
    cout << "Nilai Tugas: " << mhs.tugas << endl;
    cout << "Nilai Akhir: " << mhs.nilaiAkhir << endl;
}

int main() {
    Mahasiswa mhs[10];
    int jumlahMahasiswa;
    
    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> jumlahMahasiswa;
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        inputMahasiswa(mhs[i]);
    }
    
    // Menampilkan semua data mahasiswa
    cout << "\nData Mahasiswa yang sudah diinput: " << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        tampilMahasiswa(mhs[i]);
    }

    return 0;
}