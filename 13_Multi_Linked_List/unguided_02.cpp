#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judulBuku;
    string tanggalPengembalian;
    Buku *next;
};

struct Anggota {
    string namaAnggota;
    string idAnggota;
    Buku *headBuku;
    Anggota *next;
};

struct MultiLinkedList {
    Anggota *headAnggota;
};

void initList(MultiLinkedList &list) {
    list.headAnggota = nullptr;
}

Anggota* createAnggota(string nama, string id) {
    Anggota *newAnggota = new Anggota;
    newAnggota->namaAnggota = nama;
    newAnggota->idAnggota = id;
    newAnggota->headBuku = nullptr;
    newAnggota->next = nullptr;
    return newAnggota;
}

Buku* createBuku(string judul, string tanggal) {
    Buku *newBuku = new Buku;
    newBuku->judulBuku = judul;
    newBuku->tanggalPengembalian = tanggal;
    newBuku->next = nullptr;
    return newBuku;
}

void addAnggota(MultiLinkedList &list, Anggota *anggota) {
    if (list.headAnggota == nullptr) {
        list.headAnggota = anggota;
    } else {
        Anggota *temp = list.headAnggota;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = anggota;
    }
}

void addBuku(Anggota *anggota, Buku *buku) {
    if (anggota->headBuku == nullptr) {
        anggota->headBuku = buku;
    } else {
        Buku *temp = anggota->headBuku;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = buku;
    }
}

void deleteAnggota(MultiLinkedList &list, string idAnggota) {
    Anggota *temp = list.headAnggota, *prev = nullptr;
    while (temp != nullptr && temp->idAnggota != idAnggota) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;

    Buku *bukuTemp = temp->headBuku;
    while (bukuTemp != nullptr) {
        Buku *toDelete = bukuTemp;
        bukuTemp = bukuTemp->next;
        delete toDelete;
    }

    if (prev == nullptr) {
        list.headAnggota = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
}

void printList(const MultiLinkedList &list) {
    Anggota *tempAnggota = list.headAnggota;
    while (tempAnggota != nullptr) {
        cout << "Anggota: " << tempAnggota->namaAnggota << " (ID: " << tempAnggota->idAnggota << ")" << endl;
        Buku *tempBuku = tempAnggota->headBuku;
        while (tempBuku != nullptr) {
            cout << "  Buku: " << tempBuku->judulBuku << ", Pengembalian: " << tempBuku->tanggalPengembalian << endl;
            tempBuku = tempBuku->next;
        }
        cout << endl;
        tempAnggota = tempAnggota->next;
    }
}

int main() {
    MultiLinkedList list;
    initList(list);

    Anggota *a1 = createAnggota("Rani", "A001");
    Anggota *a2 = createAnggota("Dito", "A002");
    Anggota *a3 = createAnggota("Vina", "A003");
    addAnggota(list, a1);
    addAnggota(list, a2);
    addAnggota(list, a3);

    addBuku(a1, createBuku("Pemrograman C++", "01/12/2024"));
    addBuku(a2, createBuku("Algoritma Pemrograman", "15/12/2024"));
    addBuku(a1, createBuku("Struktur Data", "10/12/2024"));

    deleteAnggota(list, "A002");

    printList(list);

    return 0;
}
