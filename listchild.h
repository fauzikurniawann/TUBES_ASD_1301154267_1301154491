#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define first(l) l.first
#define last(l) l.last
#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define parent(p) p->parent



struct infotypechild
{
    int no_antrian;
    int id_nasabah ;
    char nama[50];
    char tgl_lahir [15];
    char jenis_transaksi[25];
    char saldo[11];
};

typedef struct element_child *address_child;

struct element_child {
    infotypechild info;
    address_child next, prev;
};

struct listchild {
    address_child first, last;
};


void createList(listchild &l);
address_child alokasi(infotypechild x);
void dealokasi(address_child &p);
void insertFirst(listchild &l,address_child prec, address_child p);
void insertLast(listchild  &l, address_child p);
void insertAfter(listchild &l, address_child p);
void deleteFirst(listchild &l, address_child &p);
void deleteLast(listchild  &l, address_child &p);
void deleteAfter(listchild &l,address_child prec, address_child &p);
address_child findElm(listchild l, infotypechild x);

#endif // LISTCHILD_H_INCLUDED

