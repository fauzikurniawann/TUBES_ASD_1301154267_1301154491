#include "listparent.h"
#include "listchild.h"
#include "menu.h"
#include <conio.h>

listparent lp;
listchild lc;
address_child c;
address_parent p;
infotypechild y;
infotypeparent x;
int i=0;
int q=0;

void pertama(){
    createList(lp);
    main_menu();
}
void main_menu(){
    int x;
    cout << "-----------------" << endl;
    cout << endl;
    cout << "......MENU......" << endl;
    cout << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. View & edit Data" << endl;
    cout << "3. Delete Data" << endl;
    cout << "4. Report" << endl;
    cout << "pilih: ";
    cin >> x;

    switch (x)
    {
    case 1:
        insertData();
        break;
    case 2:
        viewDetailData();
        break;
    case 3:
        deleteData();
        break;
    case 4:
    //    editData();
        break;
    case 5:
      //  report();
        break;
    }
}

void insertData()
{
    int y;
    cout << "....masukkan inputan...." << endl;
    cout << "1. Masukkan Data Teller " << endl;
    cout << "2. Masukkan Data Nasabah" << endl;
    cout << "pilih: ";
    cin >> y;
    switch(y){
        case 1:
            insertDataTeller();
            break;
        case 2:
            insertnasabah();
            break;

    }
}
void insertnasabah(){
    cout<<"input id_teller: ";
    cin>>x.id_teller;
    address_parent p;
    p=findElm(lp,x);
    if(info(p).id_teller == x.id_teller && p!=NULL)
    {
        cout<<"1. input id_nasabah : ";
        cin>>y.id_nasabah;
        cout<<"2. input no_antrean : ";
        cin>>y.no_antrian;
        cout<<"3. input nama : ";
        cin>>y.nama;
        cout<<"4. input tanggal-lahir : ";
        cin>>y.tgl_lahir;
        cout<<"5. input jenis kelamin : ";
        cin>>y.jenis_transaksi;
        cout<<"6. input saldo : ";
        cin>>y.saldo;
        c=alokasi(y);
        insertLast(anak(p),c);
        cout<<"data telah terinput"<<endl;
        cout<<"input data lagi? ya/tidak";
        string pilih;
        cin>>pilih;
        if(pilih =="ya"){
            insertDataTeller();
        }
        else if (pilih =="tidak")
        {
            main_menu();
        }
        else{
            cout<<"inputan salah"<<endl;
            main_menu();
        }
    }
    else if(info(p).id_teller !=x.id_teller)
    {
        cout<<"id yang di inputkan tidak ada"<<endl;
    }
}

void insertDataTeller(){
    bool cek;
    int id;
    if(i==0){
    cout<<"1. input id_teller";
    cout<<": ";
    cin>>x.id_teller;
    cout<<"2. input nama";
    cout<<": ";
    cin>>x.nama;
    cout<<"3. input posisi";
    cout<<": ";
    cin>>x.posisi;
    cout<<"4. input gaji";
    cout<<": ";
    cin>>x.gaji;
    cout<<"5. input jenis_kelamin";
    cout<<": ";
    cin>>x.jenis_kelamin;
    cout<<"5. input shift";
    cout<<": ";
    cin>>x.shift;
    p=alokasi(x);
    i++;
    insertFirst(lp,p);
    cout<<"data telah di inputkan"<<endl;
    cout<<"inputkan data lagi? ya/tidak : ";
    string a;
    cin>>a;
    if(a=="yes"){
        insertDataTeller();
    }
    else if(a=="tidak")
    {
        main_menu();
    }
    else{
        cout<<"maaf inputan salah"<<endl;
        main_menu();
    }
    //printInfo(lp);
    //insertDataTeller();
    }
    else{
        cout<<"1. input id_teller: ";
        cin>>id;
        cek=findx(lp,id);
        if(cek==true){
            x.id_teller=id;
            cout<<"1. input id_teller";
            cin>>x.id_teller;
            cout<<": ";
            cout<<"2. input nama";
            cout<<": ";
            cin>>x.nama;
            cout<<"3. input posisi";
            cout<<": ";
            cin>>x.posisi;
            cout<<"4. input gaji";
            cout<<": ";
            cin>>x.gaji;
            cout<<"5. input jenis_kelamin";
            cout<<": ";
            cin>>x.jenis_kelamin;
            cout<<"5. input shift";
            cout<<": ";
            cin>>x.shift;
            p=alokasi(x);
            printInfo(lp);
            insertAscending(lp,p);
            i++;
            cout<<"data telah di inputkan"<<endl;
            cout<<"inputkan data lagi? ya/tidak : ";
            string a;
            cin>>a;
            if(a=="yes"){
            insertDataTeller();
            }
            else if(a=="tidak")
            {
            main_menu();
            }
            else{
                cout<<"maaf inputan salah"<<endl;
                main_menu();
            }
        }
            else
            {
                cout<<"id sudah terinput";
            }

}}
void viewDetailData()
{
   int y;
   cout << "1. cari Detail Data Teller" << endl;
   cout << "2. cari Detail Data Nasabah" << endl;
   cout << "3. Edit Data" << endl;
   cout << "4. View All Data" << endl;
   cout << "pilih: ";
   cin >> y;
   switch (y)
   {
    case 1:
        caridata_teller();
        break;
    case 2:
        caridata_nasabah();
        break;
    case 3:
    //   viewAllData();
       break;
    case 4:
        view();
        break;
   }
}

void caridata_nasabah(){
    cout<<"masukkan id teller: ";
    cin>>x.id_teller;
    p=findElm(lp,x);
    if (p!=NULL && info(p).id_teller==x.id_teller)
    {
        cout<<"masukkan id nasabah: ";
        cin>>y.id_nasabah;
        c=findElm(anak(p),y);
        if(c!= NULL && info(c).id_nasabah == y.id_nasabah)
        {
            cout<<"nama :"<<info(c).nama<<endl;
            cout<<"no antrean: "<<info(c).no_antrian<<endl;
            cout<<"tanggal lahir: "<<info(c).tgl_lahir<<endl;
            cout<<"jenis transaksi: "<<info(c).jenis_transaksi<<endl;
            cout<<"saldo: "<<info(c).saldo<<endl;
        }
    }
}

void caridata_teller(){
    infotypeparent input;
    address_parent cek;
    cout<<"masukkan id_teller: ";
    cin>>input.id_teller;
    p=findElm(lp,input);
    if(p!=NULL){
        cout<<info(p).id_teller<<endl;
        cout<<info(p).nama<<endl;
        cout<<info(p).posisi<<endl;
        cout<<info(p).gaji<<endl;
        cout<<info(p).jenis_kelamin<<endl;
        cout<<info(p).shift<<endl;
        main_menu();
    }
    else{
        cout<<"id teller tidak ada";
    }
    cout<<endl;
}

void view()
{
    printInfo(lp);
}

void deleteData()
{
    int a;
    cout<<"1. delete data parent"<<endl;
    cout<<"2. delete data child"<<endl;
    cout<<"pilih: ";
    cin>>a;
    switch (a){
    case 1:
        deleteparent();
        break;
    case 2:
        deletechild();
        break;
    }
}

void deleteparent(){
    infotypeparent x;
    printInfo(lp);
    cout<<"masukkan id teller: ";
    cin>>x.id_teller;
    address_parent tempP =first(lp);
    if(findElm(lp,x)==NULL){
        cout<<"id_teller belum ada"<<endl;
        getch();
        main_menu();
    }
    else{
        //infotypeparent x;
        address_parent p;
        p = findElm(lp,x);
        if(p == first(lp)){
            cout<<"A";
            deleteFirst(lp,p);
        }
        else if(next(p)== NULL){
            deleteLast(lp,p);
        }
        else{
            do{
                if(next(tempP)==p){
                    deleteAfter(lp,tempP,p);
                }
                tempP=next(tempP);
            }while(p!=NULL);
        }
        cout<<"id parent berhasil di hapus"<<endl;
        getch();
        main_menu();
    }


}

void deletechild(){


}

//void editData
//{

//}

//void report
//{

//}


