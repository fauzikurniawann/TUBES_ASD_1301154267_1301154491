#include "listparent.h"
#include "listchild.h"

using namespace std;

void createList(listparent &l) {
    /**
    * FS : first(L) diset Nil
    */
    l.first = NULL;

}


address_parent alokasi(infotypeparent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    address_parent p;
    p = new element_parent;
    info(p) = x;
    next(p) = NULL;
    createList(anak(p));
    return p;
}

void dealokasi(address_parent &p){
    address_child q;
    dealokasi(q);
    delete p;
}


void insertFirst(listparent &l, address_parent p){
  /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    //address_parent q;
    if(l.first == NULL) {
        l.first = p;
        next(p) = NULL;
    } else {
        next(p) = first(l);
        l.first = p;
    }
}

void printInfo(listparent l) {
    address_parent p = first(l);
    cout<<"<------- ID JOINED GROUP ------>"<<endl;
    if (first(l) == NULL){
        cout<<"   NOT JOINED ANY GROUP"<<endl;
    }
    else{
        while(p !=NULL) {
            cout<<"    ID             : "<<info(p).id_teller<<endl;
            cout<<"    Name           : "<<info(p).nama<<endl;
            cout<<"    posisi         : "<<info(p).posisi<<endl;
            cout<<"    gaji           : "<<info(p).gaji<<endl;
            cout<<"    jenis kelamin  : "<<info(p).jenis_kelamin<<endl;
            cout<<"    shift          : "<<info(p).shift<<endl;
            p = next(p);
        }
    }
}



void insertAfter(listparent &l, address_parent prec, address_parent p){

    next (p)= next(prec);
    next(prec) = p;
}

void insertLast(listparent  &l, address_parent p){
    address_parent q=l.first;
    if(l.first!=NULL){
        while(next(q)!=NULL){
            q=next(q);
        }
        next(q)=p;
        next(p)=NULL;
    }
    else{
        next(q)=p;
        next(p)=NULL;
    }
}

void deleteFirst(listparent &l, address_parent &p){
    if (next(first(l)) == NULL){
        first(l) = NULL;
    }
    else{
        p = first(l);
        first(l) = next(p);
        next(p) = NULL;
    }
}

void deleteLast(listparent &l, address_parent &p){
    address_parent q = first(l);
    while (next(q) != NULL){
        q = next(q);
    }
    p = next(q);
    next(q) = NULL;
}


void deleteAfter(listparent &l,address_parent prec, address_parent &p){
    p = next(prec);
    next(prec) = next(p);
    next(p) = NULL;
}


address_parent findElm(listparent l, infotypeparent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */

    address_parent p = first(l);
        if(first(l)==NULL) {
            return NULL;
        }
        else{
            do
            {
                if( info(p).id_teller == x.id_teller)
                {
                    return p;
                }
                p=next(p);
            }
            while(p != NULL);
            return NULL;
        }

}


bool findx(listparent l, int id){
    address_parent p;
    p=first(l);
    bool cek=false;
    if(info(p).id_teller !=id){
        if(p!=NULL){
            while(p!=NULL && info(p).id_teller!=id){
                p=next(p);
            }
            if(p==NULL){
                cek=true;
            }
        }
    }
    return cek;
}


void insertAscending(listparent &l, address_parent p){
    address_parent q;
    if(first(l)==NULL){
        insertFirst(l,p);
    }
    else{
        q=first(l);
        if(q==NULL && info(q).id_teller<info(q).id_teller){
            insertLast(l,p);
        }
        else{
            while(q!=NULL && info(q).id_teller<info(q).id_teller){
                q=next(q);
            }
            if(q==NULL){
                insertLast(l,p);
            }
            else{
                address_parent r=first(l);
                while(next(r)!=q){
                    r=next(r);
                }
                insertAfter(l,r,p);
            }
        }
    }
}



