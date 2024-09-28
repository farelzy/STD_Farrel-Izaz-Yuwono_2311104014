#include <iostream>
using namespace std;

int main()
{
    // double pembelian, diskon, total;
    // cout <<"------------------"<<endl;
    // cout <<"harga : Rp";
    // cin >> pembelian;
    // diskon = 0;
    // if (pembelian > 10000)
    // {
    //     diskon = 0.5*pembelian;
    // }else{
    //     diskon = 0;
    // }
    // cout << "Diskon : Rp" <<diskon<<endl;

    // total = pembelian - diskon;
    // cout <<"Total Harga : Rp"<< total<<endl;
    // cout <<"------------------";

    // int i=1;
    // int jum;
    // cin>>jum;
    // do{
    //     cout<<"baris ke-"<<i+1<<endl;
    //     i++;

    // }while (i<jum);
    // {
    //     getchar();
    //     return 0;
    // };


    int kode_hari;
    puts("Menentukan hari\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu ");
    cin >> kode_hari;
    switch (kode_hari)
    {
    case  1: // constant-expression 
      puts("Hari Senin");
      break;
    case  2: // constant-expression 
      puts("Hari Selasa");
      break;
    case  3: // constant-expression 
      puts("Hari Rabu");
      break;
    case  4: // constant-expression 
      puts("Hari Kamis");
      break;
    case  5: // constant-expression 
      puts("Hari Jumat");
      break;
    case  6: // constant-expression 
      puts("Hari Sabtu");
      break;
    case  7: // constant-expression 
      puts("Hari Minggu");
      break;
    default:
      puts("Kode masukan salah!!!");
    }








    // int input;
    // cout << "Masukkan angka: ";
    // cin >> input;

    // for (int i = input; i >= 1; i--) {
    //     // Bagian kiri
    //     for (int j = i; j >= 1; j--) {
    //         cout << j << " ";
    //     }

    //     // Bintang di tengah
    //     cout << "= ";

    //     // Bagian kanan
    //     for (int j = 1; j <= i; j++) {
    //         cout << j << " ";
    //     }

    //     // Ganti baris
    //     cout << endl;
    // }

    // // Baris terakhir dengan hanya "*"
    // cout << " * " << endl;

    // return 0;
}