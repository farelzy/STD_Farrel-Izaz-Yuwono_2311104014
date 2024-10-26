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

    void insertSorted_2311104014(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr || head->data >= newNode->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < newNode->data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display_2311104014() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    int elemen;
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan elemen ke-" << i+1 << ": ";
        cin >> elemen;
        sll.append_2311104014(elemen);
    }

    int tambahan;
    cout << "Masukkan elemen tambahan yang ingin disisipkan secara terurut: ";
    cin >> tambahan;
    sll.insertSorted_2311104014(tambahan);

    cout << "List setelah elemen baru dimasukkan: ";
    sll.display_2311104014();

    return 0;
}