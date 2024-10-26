#include "list.h"

void createList(List &L) {
    first(L) = nil;
}

address allocate(infotype x) {
    address P = new elmtList;
    info(P) = x;
    next(P) = nil;
    return P;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    address P = first(L);
    while (P != nil) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

void insertLast(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != nil) {
            last = next(last);
        }
        next(last) = P;
    }
}
