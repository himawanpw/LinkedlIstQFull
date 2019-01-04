##include <iostream>
#include <conio.h>

using namespace std;

typedef struct myLinkedList{
    string nama;
    int umur;
    myLinkedList *next;
}myList;

myList *head; myList *tail;
int n=0;
void tambah_depan()
{
    myList *baru;

    baru=new myList;
    cout<<"Menambah Data Baru Di Depan "<<endl;
    cout<<"Masukan Data Baru "<<endl;
    cout<<"Nama : ";cin>>baru->nama;
    cout<<"Umur : ";cin>>baru->umur;
    baru->next=NULL;
    if(head==NULL)
    {head=baru;tail=baru;}
    else{baru->next=head;head=baru;}
    cout<<"Node Sudah Berhasil Ditambahkan Di Posisi Depan "<<endl;
}
void tambah_akhir()
{
    myList *baru;

    baru=new myList;
    cout<<"Menambah Data Baru Di Terkahir "<<endl;
    cout<<"Masukan Data Baru "<<endl;
    cout<<"Nama : ";cin>>baru->nama;
    cout<<"Umur : ";cin>>baru->umur;
    baru->next=NULL;
    if(head==NULL)
    {head=baru;tail=baru;}
    else{tail->next=baru;tail=baru;}
    cout<<"Node Sudah Berhasil Ditambahkan Di Posisi Terakhir "<<endl;
}
void cetak_list (myList *x,myList *y)
{
    myList *bantu;
    bantu==new myList;
    bantu=head;
    cout<<"Berikut Adalah Data Di Linked List "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Nomor	Nama	Umur	"<<endl;
    cout<<"---------------------------------------"<<endl;
    int i=0;
    while(bantu!=NULL)
    {
        cout<<""<<++i<<"	"<<bantu->nama<<"	"<<bantu->umur<<endl;
        bantu=bantu->next;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Jumlah Node Yang Ada : "<<i<<" buah"<<endl;
    delete bantu;
}
void hapus_depan()
{
    myList *hapus;

    hapus=new myList;
    cout<<"Menghapus Data Di Posisi Depan "<<endl;
    hapus=head;
    head=head->next;
    cout<<"Data Yang Di Hapus Adalah : "<<endl;
    cout<<"Nama : "<<hapus->nama<<endl;
    cout<<"Umur : "<<hapus->umur<<endl;
    delete hapus;
    cout<<"Note Sudah Di Hapus "<<endl;
}
void hapus_akhir()
{
    myList *hapus;
    myList *bantu;

    bantu=new myList;
    hapus=new myList;
    bantu=head;
    if(head==tail){hapus_depan();}
    else{
        while((bantu->next->next)!=NULL){bantu=bantu->next;}

        hapus=bantu->next;
        cout<<"Data Note Terakhir Adalah : "<<endl;
        cout<<"Nama : "<<hapus->nama<<endl;
        cout<<"Umur : "<<hapus->umur<<endl;
        bantu->next=NULL;
        tail=bantu;
        cout<<"Note Terakhir Sudah Di Hapus "<<endl;
        delete hapus;
    }
}
void sisip_node ()
{
    myList *baru; baru=new myList;
    myList *bantu; bantu=new myList;
    bool ada=false;
    string sisip;
    cout<<"Menyisipkan node ke dalam Linked List "<<endl;
    cout<<"Masukan data ke node yang akan di sisip "<<endl;
    cout<<"Masukan Nama : ";cin>>baru->nama;
    cout<<"Masukan Umur : ";cin>>baru->umur;
    baru->next=NULL;
    cetak_list(head,tail);
    cout<<"Node tersebut akan diletakan sesudah nama apa ? ";cin>>sisip;
    bantu=head;
    if(tail->nama==sisip) {tail->next=baru;tail=baru;ada=true;}
    else {while (bantu=NULL)
        {
            if(bantu->nama==sisip);
            {
                baru->next=bantu->next;
                bantu->next=baru;
                ada=true;
                bantu=bantu->next;}
        }
        if(ada==true)
        {cout<<"Penyisipan Berhasil"<<endl;}
        else{cout<<"Penyisipan Gagal "<<endl;}
    }
}
void hapus_nama ()
{
    myList *hapus; hapus=new myList;
    myList *bantu; bantu=new myList;
    string nama_hapus;
    bool ada=false;

    cout<<"Menghapus Nama Tertentu Dari Linked List "<<endl;
    cetak_list(head,tail);
    cout<<"Masukan Nama Yang Akan Di Hapus Dari Linked List";cin>>nama_hapus;
    if(head->nama==nama_hapus ){ada=true;hapus_depan();}
    else if(tail->nama==nama_hapus) {
        ada=true;hapus_akhir();}
    else
    {
        bantu=head;
        while (bantu->next=NULL)
        {
            if(bantu->next->nama==nama_hapus)
            {
                ada=false;
                hapus=bantu->next;
                cout<<"Node Dengan Nama "<<bantu->nama<<"akan di hapus"<<endl;
                bantu->next=hapus->next;
            }
            bantu=bantu->next;
        }
    }
    if(ada=true){cout<<"Penghapusan Berhasil"<<endl;}
    else { cout<<"Penghapusan Gagal, Nama Tidak Ada "<<endl;}
    delete hapus;
}
void tambah_nomor ()
{
    myList *baru;  baru=new myList;
    int nomor=0;
    cout<<"Menambahkan Node Berdasar Nomor "<<endl;
    cetak_list(head,tail);
    ulang:
    cout<<"Anda Akan Menyisipkan Node di Nomor Berapa?";cin>>nomor;
    if((nomor<1) || (nomor>n+1)) {
        cout<<"Nomor Tidak Valid, Ulangi "<<endl;
        goto ulang;
    }

    if(nomor==1){tambah_depan();}
    else if(nomor==n+1) {tambah_akhir();}
    else
    {
        myList *bantu; bantu=new myList;
        cout<<"Masukan Data Yang Baru  "<<endl;
        cout<<"Masukan  Nama : ";cin>>baru->nama;
        cout<<"Masukan Umur  : ";cin>>baru->umur;
        baru->next=NULL;
        bantu=head; int i=0;
        while(bantu->next!=NULL)
        {
            i++;
            if(i==nomor-1)
            {
                baru->next=bantu->next;
                bantu->next=baru;
                cout<<"Node Baru Sudah Di Tambahkan Di Nomor "<<nomor<<endl;
            }
            bantu=bantu->next;
        }
    }

}
void hapus_nomor ()
{
    myList *hapus;  hapus=new myList;
    myList *bantu;  bantu=new myList;
    cetak_list(head,tail);
    int nomor=0;
    ulang:
    cout<<"Masukan Nomor Node Yang Akan Di Hapus";cin>>nomor;
    if((nomor<1) || (nomor>n)) {
        cout<<"Nomor Node Tidak Ada, Ulangi "<<endl;
        goto ulang;
    }

    else if(nomor==1){hapus_depan();}
    else if(nomor==n)  {hapus_akhir();}
    else
    {
        bantu=head; int i=0;
        while(bantu->next!=NULL)
        {
            i++;
            if(i==nomor-1)
            {
                hapus=bantu->next;
                bantu->next=hapus->next;
                cout<<"Anda Menghapus Node Nomor "<<nomor<<" Data Sebagai Berikut :"<<endl;
                cout<<"Nama : "<<hapus->nama<<endl;
                cout<<"Umur : "<<hapus->umur<<endl;
                delete hapus;
            }
            bantu=bantu->next;
        }
    }
}
void cari_dinode ()
{
    myList *bantu; bantu=new myList;
    string cari;
    int i=0; bool ada=false;
    cout<<"Mencari Data Dalam Linked List "<<endl;
    cout<<"Masukan Nama Yang Akan Anda Cari : ";cin>>cari;
    bantu=head;
    while(bantu!=NULL)
    {
        i++;
        if(bantu->nama==cari){
            ada=true;
            cout<<"Nama : "<<cari<<"Ada Di Node Nomor "<<i<<endl;}
        bantu=bantu->next;
    }
    if(not ada)
    {
        cout<<"Nama : "<<cari<<"Tidak Ditemukan "<<endl;
    }
}
int main()
{
    head=NULL;tail=NULL;
    int pilih=0;
    lagi:
    system("cls");
    cout<<"Pilih Menu "<<endl;
    cout<<"1. Tambah Awal "<<endl;
    cout<<"2. Tambah Akhir "<<endl;
    cout<<"3. Cetak Linked List "<<endl;
    cout<<"4. Hapus Awal "<<endl;
    cout<<"5. Hapus Akhir "<<endl;
    cout<<"6. Sisip Data "<<endl;
    cout<<"7. Hapus Nama "<<endl;
    cout<<"8. Tambah Berdasar Nomor Node "<<endl;
    cout<<"9. Hapus Berdasar Nomor Node "<<endl;
    cout<<"10. Mencari Data Di Linked List "<<endl;
    cout<<"0. Selesai "<<endl;
    cout<<"Masukan Pilihan : ";cin>>pilih;
    switch(pilih)
    {
        case 1:tambah_depan();
            break;
        case 2:tambah_akhir();
            break;
        case 3:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{cetak_list(head,tail);}
            break;
        case 4:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{hapus_depan();}
            break;
        case 5:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{hapus_akhir();}
            break;
        case 6:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{sisip_node();}
            break;
        case 7:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{hapus_nama();}
            break;
        case 8:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{tambah_nomor();}
            break;
        case 9:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{hapus_nomor();}
            break;
        case 10:if(head==NULL){cout<<"Data Kosong "<<endl;}
            else{cari_dinode();}
            break;
        case 0:
            cout<<"Terimakasih "<<endl;
            break;
        default :
            cout<<"Pilihan Anda Salah "<<endl;
            break;
    }
    system("pause");
    if(pilih!=0) goto lagi;
    delete head;
    delete tail;
}
