#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertDepan(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void insertBelakang(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool cariNode(int nilai) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == nilai) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int panjangLinkedList() {
    int panjang = 0;
    Node* temp = head;
    while (temp != NULL) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

void cetakLinkedList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);
    if (cariNode(20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }
    cout << "Panjang linked list: " << panjangLinkedList() << endl;
    cetakLinkedList(); // Output: 5 -> 10 -> 20 -> NULL
    return 0;
}
