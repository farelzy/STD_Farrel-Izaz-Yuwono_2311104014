#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertDepan(int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void insertBelakang(int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void cetakLinkedList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void hapusNode(int nilai) {
    Node* temp = head;
    Node* prev = NULL;

    // Jika node yang dihapus adalah head
    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        return;
    }

    // Mencari node yang akan dihapus
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node tidak ditemukan
    if (temp == NULL) return;

    // Hapus node
    prev->next = temp->next;
    delete temp;
}

int main()
{
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);
    cout <<"Sebelum ada Penghapusan Node : ";
    cetakLinkedList(); // Output: 5 -> 10 -> 20 -> NULL
    hapusNode(10);
    cout <<"Setelah ada Penghapusan Node : ";
    cetakLinkedList();
    return 0;
}
