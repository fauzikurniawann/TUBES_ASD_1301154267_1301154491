#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED

#include <iostream>

using namespace std;

#include "listchild.h"

#define first(l) l.first
#define next(p) p->next
#define info(p) p->info
#define anak(p) p->anak



struct infotypeparent
{
    int id_teller;
    char nama[20];
    char posisi[30];
    char gaji[20];
    char jenis_kelamin[10];
    char shift[20];

};

typedef struct element_parent *address_parent;

struct element_parent{
    listchild anak;
    infotypeparent info;
    address_parent next;

};

struct listparent{
    address_parent first;
};



void createList(listparent &l);
address_parent alokasi(infotypeparent x);
void dealokasi(address_parent &p);
address_parent findElm(listparent l, infotypeparent x);
bool findx(listparent l, int id);
void printInfo(listparent L);
void insertFirst(listparent &l, address_parent p);
void insertAfter(listparent &l, address_parent p);
void insertLast(listparent  &l, address_parent p);
void deleteFirst(listparent &l, address_parent &p);
void deleteLast(listparent &l, address_parent &p);
void deleteAfter(listparent &l, address_parent prec, address_parent &p);
void insertAscending(listparent &l, address_parent p);

#endif // LISTPARENT_H_INCLUDED
