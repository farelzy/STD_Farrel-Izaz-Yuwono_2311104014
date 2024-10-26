#include <iostream>
#include <string>
using namespace std;

struct Node {
    int NIM;
    string nama;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void tambahMahasiswa(int nim, string nama) {
        Node* newNode = new Node();
        newNode->NIM = nim;
        newNode->nama = nama;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Mahasiswa dengan NIM " << nim << " dan nama " << nama << " berhasil ditambahkan." << endl;
    }

    void cariMahasiswa(int nim) {
        Node* current = head;
        while (current != nullptr) {
            if (current->NIM == nim) {
                cout << "Mahasiswa dengan NIM " << nim << " ditemukan. Nama: " << current->nama << endl;
                return;
            }
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    void tampilkanMahasiswa() {
        Node* current = head;
        while (current != nullptr) {
            cout << "NIM: " << current->NIM << ", Nama: " << current->nama << endl;
            current = current->next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int pilihan, nim;
    string nama;

    while (true) {
        cout << "\nMenu:\n1. Tambah Mahasiswa\n2. Cari Mahasiswa berdasarkan NIM\n3. Tampilkan Semua Mahasiswa\n4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            list.tambahMahasiswa(nim, nama);
            break;
        case 2:
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            list.cariMahasiswa(nim);
            break;
        case 3:
            list.tampilkanMahasiswa();
            break;
        case 4:
            cout << "Keluar program.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
