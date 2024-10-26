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

    // Fungsi untuk menambahkan elemen di awal list
    void insertFirst_2311104014(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;  // Jika list kosong, tail juga menunjuk newNode
        }
        head = newNode;
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
            head = newNode;  // Jika list kosong, head juga menunjuk newNode
        }
        tail = newNode;
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
    dll.insertFirst_2311104014(elemen);

    cout << "Masukkan elemen kedua di awal = ";
    cin >> elemen;
    dll.insertFirst_2311104014(elemen);

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemen;
    dll.insertLast_2311104014(elemen);

    cout << "DAFTAR ANGGOTA LIST: ";
    dll.displayForward_2311104014();

    return 0;
}
