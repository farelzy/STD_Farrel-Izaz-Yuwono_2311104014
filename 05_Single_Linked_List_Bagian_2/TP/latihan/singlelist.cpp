#include <iostream>
#include "singlelist.h"
using namespace std;

void createList(List *L) {
    L->First = NULL;
}

address alokasi(infotype X) {
    address P = new ElmtList;
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

address findElm(List L, infotype X) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int sumInfo(List L) {
    int sum = 0;
    address P = L.First;
    while (P != NULL) {
        sum += P->info;
        P = P->next;
    }
    return sum;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List *L, address P) {
    P->next = L->First;
    L->First = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;

}
