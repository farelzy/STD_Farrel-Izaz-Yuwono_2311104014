#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;

    Pohon(char data, Pohon* left = NULL, Pohon* right = NULL, Pohon* parent = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
};

Pohon *root = NULL;

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon(data);
        cout << "Node " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "Root sudah ada." << endl;
    }
}

Pohon *InsertLeft(char data, Pohon *node) {
    if (node->left != NULL) {
        cout << "Node " << node->data << " sudah memiliki child kiri." << endl;
        return NULL;
    }
    Pohon *baru = new Pohon(data, NULL, NULL, node);
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan sebagai child kiri dari " << node->data << endl;
    return baru;
}

Pohon *InsertRight(char data, Pohon *node) {
    if (node->right != NULL) {
        cout << "Node " << node->data << " sudah memiliki child kanan." << endl;
        return NULL;
    }
    Pohon *baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan sebagai child kanan dari " << node->data << endl;
    return baru;
}

void retrieve(Pohon *node) {
    if (node) {
        cout << "Data node: " << node->data << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

void find(Pohon *node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Data node: " << node->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data : '-') << endl;
    cout << "Child kiri: " << (node->left ? node->left->data : '-') << endl;
    cout << "Child kanan: " << (node->right ? node->right->data : '-') << endl;
}

void tampilkanDescendantHelper(Pohon *node) {
    if (node == NULL) return;
    if (node->left != NULL) {
        cout << node->left->data << " ";
        tampilkanDescendantHelper(node->left);
    }
    if (node->right != NULL) {
        cout << node->right->data << " ";
        tampilkanDescendantHelper(node->right);
    }
}

void tampilkanDescendant(Pohon *node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Descendant dari node " << node->data << ": ";
    tampilkanDescendantHelper(node);
    cout << endl;
}

Pohon* cariNode(Pohon* node, char data) {
    if (node == NULL) return NULL;
    if (node->data == data) return node;
    Pohon* foundNode = cariNode(node->left, data);
    if (foundNode == NULL) foundNode = cariNode(node->right, data);
    return foundNode;
}

void menu() {
    int pilihan;
    char data, parentData;
    Pohon *node, *parentNode;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Buat Root" << endl;
        cout << "2. Tambah Child Kiri" << endl;
        cout << "3. Tambah Child Kanan" << endl;
        cout << "4. Tampilkan Data Node" << endl;
        cout << "5. Tampilkan Descendant" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                cout << "Masukkan data untuk child kiri: ";
                cin >> data;
                parentNode = cariNode(root, parentData);
                if (parentNode) InsertLeft(data, parentNode);
                else cout << "Node parent tidak ditemukan." << endl;
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                cout << "Masukkan data untuk child kanan: ";
                cin >> data;
                parentNode = cariNode(root, parentData);
                if (parentNode) InsertRight(data, parentNode);
                else cout << "Node parent tidak ditemukan." << endl;
                break;
            case 4:
                cout << "Masukkan data node yang ingin ditampilkan: ";
                cin >> data;
                node = cariNode(root, data);
                retrieve(node);
                break;
            case 5:
                cout << "Masukkan data node untuk menampilkan descendant: ";
                cin >> data;
                node = cariNode(root, data);
                tampilkanDescendant(node);
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}