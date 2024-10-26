#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void append_2311104014(int data) {
        Node* newNode = new Node();
        newNode->data = data;
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
    }

    void searchElement_2311104014(int value) {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Elemen ditemukan di alamat node " << current << " dan urutan ke-" << position << endl;
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Elemen tidak ditemukan dalam list" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    int elemen;
    for (int i = 0; i < 6; i++) {
        cout << "Masukkan elemen ke-" << i+1 << ": ";
        cin >> elemen;
        sll.append_2311104014(elemen);
    }

    int nilai_cari;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> nilai_cari;
    sll.searchElement_2311104014(nilai_cari);

    return 0;
}
