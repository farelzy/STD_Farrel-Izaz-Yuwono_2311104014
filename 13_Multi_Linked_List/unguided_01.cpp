#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string namaProyek;
    int durasi; // dalam bulan
    Proyek *next;
};

struct Pegawai {
    string namaPegawai;
    string idPegawai;
    Proyek *headProyek;
    Pegawai *next;
};

struct MultiLinkedList {
    Pegawai *headPegawai;
};

void initList(MultiLinkedList &list) {
    list.headPegawai = nullptr;
}

Pegawai* createPegawai(string nama, string id) {
    Pegawai *newPegawai = new Pegawai;
    newPegawai->namaPegawai = nama;
    newPegawai->idPegawai = id;
    newPegawai->headProyek = nullptr;
    newPegawai->next = nullptr;
    return newPegawai;
}

Proyek* createProyek(string nama, int durasi) {
    Proyek *newProyek = new Proyek;
    newProyek->namaProyek = nama;
    newProyek->durasi = durasi;
    newProyek->next = nullptr;
    return newProyek;
}

void addPegawai(MultiLinkedList &list, Pegawai *pegawai) {
    if (list.headPegawai == nullptr) {
        list.headPegawai = pegawai;
    } else {
        Pegawai *temp = list.headPegawai;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pegawai;
    }
}

void addProyek(Pegawai *pegawai, Proyek *proyek) {
    if (pegawai->headProyek == nullptr) {
        pegawai->headProyek = proyek;
    } else {
        Proyek *temp = pegawai->headProyek;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = proyek;
    }
}

void deleteProyek(Pegawai *pegawai, string namaProyek) {
    Proyek *temp = pegawai->headProyek, *prev = nullptr;
    while (temp != nullptr && temp->namaProyek != namaProyek) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (prev == nullptr) {
        pegawai->headProyek = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
}

void printList(const MultiLinkedList &list) {
    Pegawai *tempPegawai = list.headPegawai;
    while (tempPegawai != nullptr) {
        cout << "Pegawai: " << tempPegawai->namaPegawai << " (ID: " << tempPegawai->idPegawai << ")" << endl;
        Proyek *tempProyek = tempPegawai->headProyek;
        while (tempProyek != nullptr) {
            cout << "  Proyek: " << tempProyek->namaProyek << ", Durasi: " << tempProyek->durasi << " bulan" << endl;
            tempProyek = tempProyek->next;
        }
        cout << endl;
        tempPegawai = tempPegawai->next;
    }
}

int main() {
    MultiLinkedList list;
    initList(list);

    Pegawai *p1 = createPegawai("Andi", "P001");
    Pegawai *p2 = createPegawai("Budi", "P002");
    Pegawai *p3 = createPegawai("Citra", "P003");
    addPegawai(list, p1);
    addPegawai(list, p2);
    addPegawai(list, p3);

    addProyek(p1, createProyek("Aplikasi Mobile", 12));
    addProyek(p2, createProyek("Sistem Akuntansi", 8));
    addProyek(p3, createProyek("E-commerce", 10));
    addProyek(p1, createProyek("Analisis Data", 6));

    deleteProyek(p1, "Aplikasi Mobile");

    printList(list);

    return 0;
}
