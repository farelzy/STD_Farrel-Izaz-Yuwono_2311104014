#include <iostream>
using namespace std;

struct Node {
    int data;
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

    // Fungsi untuk menambahkan elemen di akhir list
    void insertLast_2311104014(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    // Fungsi untuk menghapus elemen pertama
    void deleteFirst_2311104014() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada elemen yang dihapus." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List menjadi kosong
        }
        delete temp;
    }

    // Fungsi untuk menghapus elemen terakhir
    void deleteLast_2311104014() {
        if (tail == nullptr) {
            cout << "List kosong, tidak ada elemen yang dihapus." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // List menjadi kosong
        }
        delete temp;
    }

    // Fungsi untuk menampilkan list dari depan ke belakang
    void displayForward_2311104014() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int elemen;
    cout << "Masukkan elemen pertama = ";
    cin >> elemen;
    dll.insertLast_2311104014(elemen);

    cout << "Masukkan elemen kedua di akhir = ";
    cin >> elemen;
    dll.insertLast_2311104014(elemen);

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemen;
    dll.insertLast_2311104014(elemen);

    cout << "DAFTAR ANGGOTA LIST: ";
    dll.displayForward_2311104014();

    dll.deleteFirst_2311104014();
    dll.deleteLast_2311104014();

    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    dll.displayForward_2311104014();

    return 0;
}
