#include<iostream> //yg paling penting
#include<fstream>  //utk buat file
//jangan lupa gunakan yg std
using namespace std;

string eja(int angka){//fungsi eja angka
    //database angka
    string nomor[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    if(angka < 0)return "negatif " + eja(-angka);
    else if(angka < 12)return nomor[angka];
    else if(angka < 20)return nomor[angka % 10] + " belas ";
    else if(angka < 100)return nomor[angka / 10] + " puluh " + nomor[angka % 10];
    //else if(angka < 200)return "seratus " + eja(angka % 100);
    else if(angka < 1000)return ((angka < 200)? "seratus " : eja(angka / 100) + " ratus ") + eja(angka % 100);
    //else if(angka < 2000)return "seribu " + eja(angka % 1000);
    else if(angka < 10000)return ((angka < 2000)? "seribu ": nomor[angka / 1000] + " ribu ") + eja(angka % 1000);
    //jika tidak sesuai dengan semua if diatas...
    return "angka Tidak boleh mencapai sepuluh ribu!";
}

int main(){//fungsi utama
    //deklarasi awal
    int angka;
    string pilihan = "";
    ofstream fileku("coba.txt");
    //sampai mati ngulang terus :v
    while(true){
        //savepoint :v
        awal :
        cout<<"masukkan angka : ";cin>>angka;
        //jika input tidak sesuai
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"inputan tidak valid, harap ulangi!"<<endl;
            //load savepoint :v
            goto awal;
        }
        //hanya untuk 0...
        if(angka != 0){
            cout<<eja(angka)<<endl;
            fileku<<angka<<" = " + eja(angka)<<endl;
        }else{
            cout<<"Nol"<<endl;
            fileku<<angka<<" = Nol"<<endl;
        }
        //pilihan diuulang
        cout<<"Ingin diulang? (y/n)"<<endl<<"jawab : ";cin>>pilihan;
        if(pilihan == "n" || pilihan == "N"){
            //jangan lupa tutup file sebelum di akhiri...
            fileku.close();
            return false;
        }
    }
}
