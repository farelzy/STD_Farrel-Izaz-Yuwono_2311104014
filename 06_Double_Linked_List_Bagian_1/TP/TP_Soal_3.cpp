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

    // Fungsi untuk menampilkan list dari belakang ke depan
    void displayBackward_2311104014() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int elemen;
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan elemen ke-" << i << ": ";
        cin >> elemen;
        dll.insertLast_2311104014(elemen);
    }

    cout << "Daftar elemen dari depan ke belakang: ";
    dll.displayForward_2311104014();

    cout << "Daftar elemen dari belakang ke depan: ";
    dll.displayBackward_2311104014();

    return 0;
}