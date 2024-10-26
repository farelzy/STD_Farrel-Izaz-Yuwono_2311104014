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

    void bubbleSort_2311104014() {
        bool swapped;
        Node* current;
        Node* lastPtr = nullptr;

        if (head == nullptr)
            return;

        do {
            swapped = false;
            current = head;

            while (current->next != lastPtr) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            lastPtr = current;
        } while (swapped);
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
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan elemen ke-" << i+1 << ": ";
        cin >> elemen;
        sll.append_2311104014(elemen);
    }

    cout << "Sebelum diurutkan: ";
    sll.display_2311104014();

    sll.bubbleSort_2311104014();

    cout << "Setelah diurutkan: ";
    sll.display_2311104014();

    return 0;
}
