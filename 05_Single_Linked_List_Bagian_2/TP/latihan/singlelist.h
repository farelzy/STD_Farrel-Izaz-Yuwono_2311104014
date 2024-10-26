#ifndef SINGLELIST_H
#define SINGLELIST_H

typedef int infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);
void insertFirst(List *L, address P);
void printInfo(List L);
address findElm(List L, infotype X);
int sumInfo(List L);

#endif
