#include <iostream>
using namespace std;

struct Node {
    string nama;
    int NIM;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isFull() {
    return false;
}

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, int NIM) {
    Node* newNode = new Node{nama, NIM, nullptr};
    if (isEmpty()) {
        front = back = newNode;
    } else if (NIM < front->NIM) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->NIM <= NIM) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            back = newNode;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

void viewQueue() {
    cout << "\nData Antrian Mahasiswa: " << endl;
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = front;
        int pos = 1;
        while (temp != nullptr) {
            cout << pos++ << ". Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
            temp = temp->next;
        }
    }
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
    cout << "Antrian sudah dikosongkan!" << endl;
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int pilihan;
    string nama;
    int NIM;

    do {
        cout << "\nMenu Antrian Mahasiswa\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Hapus Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Hapus Semua Antrian\n";
        cout << "5. Jumlah Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> NIM;
                enqueueAntrian(nama, NIM);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Jumlah Antrian: " << countQueue() << endl;
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}


// perubahan
// Array ke SLL

// struct Node {
//     string nama;
//     int NIM;
//     Node* next;
// };

// Node* front = nullptr;
// Node* back = nullptr;



// disini untuk menyimpan data mahasiswa
// struct Node {
//     string nama;
//     int NIM;
//     Node* next;
// };


// fungsi enqueue juga di perbarui untuk parameter nama dan nim
// void enqueueAntrian(string nama, int NIM) {
//     Node* newNode = new Node{nama, NIM, nullptr};
//     ...
// }


// disitu juga sudah menerima input by user