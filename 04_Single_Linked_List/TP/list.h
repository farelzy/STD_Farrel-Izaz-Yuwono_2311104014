#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
#define nil NULL

typedef int infotype;
typedef struct elmtList *address;

struct elmtList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif
