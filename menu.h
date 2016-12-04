#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "listparent.h"
#include "listchild.h"
#include <conio.h>


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

void createList(listparent &l);
address_parent alokasi(infotypeparent x);
void printInfo(listparent L);
void insertFirst(listparent &l, address_parent p);
void insertAfter(listparent &l, address_parent prec, address_parent p);
bool list_empty(listparent l);
void insertLast(listparent  &l, address_parent p);
void deleteFirst(listparent &l, address_parent &p);
void deleteLast(listparent &l, address_parent &p);
void deleteAfter(listparent &l, address_parent &p);

void pertama();
void caridata_teller();
void caridata_nasabah();
void main_menu();
void insertData();
void viewDetailData();
void insertDataTeller();
void insertnasabah();
void deleteData();
void editData();
void report();
void deleteparent();
void deletechild();
void view();

#endif // MENU_H_INCLUDED
