#include "list.h"

int main() {
    List L;
    createList(L);

    // Isi 3 digit NIM terakhir
    address P1 = allocate(0);  // contoh: NIM terakhir 742
    address P2 = allocate(1);
    address P3 = allocate(4);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);

    printInfo(L);  // Output akan: 2 7 4
    return 0;
}
