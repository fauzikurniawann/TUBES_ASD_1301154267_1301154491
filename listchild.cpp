#include "listchild.h"

void createList(listchild &l)
{
    first(l)=NULL;
    last(l) =NULL;
}

address_child alokasi(infotypechild x){
    address_child p;
    p=new element_child;
    info(p)=x;
    next(p)=NULL;
    prev(p)=NULL;
    return p;
}
void dealokasi(address_child &p){
    delete p;
}
void insertFirst(listchild &l, address_child p)
{
    if(first(l)==NULL){
        first(l)=p;
        last(l)=p;
    }
    else{
        next(p)=first(l);
        prev(first(l))=p;
        first(l)=p;
    }
}
void printInfo(listchild l) {
    address_child p = first(l);
    while(p !=NULL) {
        cout <<"->"<<info(p).no_antrian;
        cout <<"->"<<info(p).id_nasabah;
        cout <<"->"<<info(p).nama;
        cout <<"->"<<info(p).tgl_lahir;
        cout <<"->"<<info(p).jenis_transaksi;
        cout <<"->"<<info(p).saldo << endl;
        p = next(p);
    }
}



void insertLast(listchild  &l, address_child p)
{
    if(first(l)==NULL)
    {
        first(l)=p;
        last(l)=p;
    }
    else{
        prev(p)=last(l);
        next(last(l))=p;
        last(l)=p;
    }
}

void insertAfter(listchild  &l,address_child prec, address_child p)
{
    next(p)=next(prec);
    prev(p)=prec;
    prev(next(prec))=p;
    next(prec)=p;
}

void deleteFirst(listchild &l, address_child &p)
{
    if(first(l)!=NULL){
        p=first(l);

        if(first(l)==last(l)){
            last(l)=NULL;
            first(l)=NULL;
        }
        else{
            first(l)=next(p);
            prev(first(l))=NULL;
            next(p)=NULL;
        }
    }
}

void deleteLast(listchild  &l, address_child &p)
{
    if(first(l)!=NULL){
        p=last(l);

        if (first(l)==last(l)){
            first(l)=NULL;
            last(l)=NULL;
        }
        else{
            last(l)=prev(p);
            next(last(l))=NULL;
            prev(p)=NULL;
        }
    }
}

void deleteAfter(listchild &l,address_child prec, address_child &p)
{
    p=next(prec);

    next(prec)=next(p);
    prev(next(prec))=prev(p);

    next(p)=NULL;
    prev(p)=NULL;
}
address_child findElm(listchild l, infotypechild x){
    address_child p;
    if(first(l)){
        p=NULL;
    }
    else{
        p=first(l);
        while(p!=NULL && info(p).id_nasabah !=x.id_nasabah)
        {
            p=next(p);
        }
    }
    return p;
}

