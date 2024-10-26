#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data buku
struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan buku di akhir list
    void tambahBuku_2311104014(int id, string judul, string penulis) {
        Node* newNode = new Node();
        newNode->idBuku = id;
        newNode->judulBuku = judul;
        newNode->penulisBuku = penulis;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;  // Jika list kosong, head juga menunjuk newNode
        }
        tail = newNode;
    }

    // Fungsi untuk menampilkan buku dari awal ke akhir
    void tampilDariDepan_2311104014() {
        Node* current = head;
        if (current == nullptr) {
            cout << "Daftar buku kosong!" << endl;
            return;
        }
        cout << "Daftar buku dari depan ke belakang:" << endl;
        while (current != nullptr) {
            cout << "ID Buku: " << current->idBuku << ", Judul: " << current->judulBuku << ", Penulis: " << current->penulisBuku << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan buku dari akhir ke awal
    void tampilDariBelakang_2311104014() {
        Node* current = tail;
        if (current == nullptr) {
            cout << "Daftar buku kosong!" << endl;
            return;
        }
        cout << "Daftar buku dari belakang ke depan:" << endl;
        while (current != nullptr) {
            cout << "ID Buku: " << current->idBuku << ", Judul: " << current->judulBuku << ", Penulis: " << current->penulisBuku << endl;
            current = current->prev;
        }
    }
};

// Program utama
int main() {
    DoublyLinkedList dll;
    int pilihan, id;
    string judul, penulis;

    while (true) {
        cout << "\nMenu:\n1. Tambah Buku\n2. Tampilkan Buku dari Depan ke Belakang\n3. Tampilkan Buku dari Belakang ke Depan\n4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan ID Buku: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan Judul Buku: ";
            getline(cin, judul);
            cout << "Masukkan Penulis Buku: ";
            getline(cin, penulis);
            dll.tambahBuku_2311104014(id, judul, penulis);
            break;
        case 2:
            dll.tampilDariDepan_2311104014();
            break;
        case 3:
            dll.tampilDariBelakang_2311104014();
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
