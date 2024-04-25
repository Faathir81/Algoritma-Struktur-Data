/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 02 (Nomor 2)
*/
#include <iostream>
#include <iomanip> 
using namespace std;

struct FatirPelanggan 
{
    string Fatirnama;
    string Fatiralamat;
    int Fatirumur;
    char Fatirjeniskelamin;
    int Fatirnotelp;
};

int main() 
{
    int Fatirjumlah_pelanggan;
    cout << "Masukkan jumlah pelanggan: ";
    cin >> Fatirjumlah_pelanggan;
    
    FatirPelanggan *Fatirdaftar_pelanggan = new FatirPelanggan[Fatirjumlah_pelanggan]; 
    
    for (int Fatiri = 0; Fatiri < Fatirjumlah_pelanggan; Fatiri++) 
    {
        cout << "Pelanggan " << Fatiri+1 << endl;
        cout << "Nama Pelanggan Toko          : ";
        cin >> Fatirdaftar_pelanggan[Fatiri].Fatirnama;
        cout << "Alamat Pelanggan Toko        : ";
        cin >> Fatirdaftar_pelanggan[Fatiri].Fatiralamat;
        cout << "Umur Pelanggan Toko          : ";
        cin >> Fatirdaftar_pelanggan[Fatiri].Fatirumur;
        cout << "Jenis Kelamin Pelanggan[L/P] : ";
        cin >> Fatirdaftar_pelanggan[Fatiri].Fatirjeniskelamin;
        cout << "No telp Pelanggan            : ";
        cin >> Fatirdaftar_pelanggan[Fatiri].Fatirnotelp;
        cout << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                        Daftar Pelanggan :" <<endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(6) << "| Nama" << setw(15) << "| Alamat" << setw(17) << "| Umur " << setw(20) << "| Jenis Kelamin " << setw(10) << "| No Telp |" << endl;
    for (int Fatiri = 0; Fatiri < Fatirjumlah_pelanggan; Fatiri++) 
    {
        cout << setw(6) << Fatirdaftar_pelanggan[Fatiri].Fatirnama << setw(17) << Fatirdaftar_pelanggan[Fatiri].Fatiralamat << setw(15) << Fatirdaftar_pelanggan[Fatiri].Fatirumur << setw(15) << Fatirdaftar_pelanggan[Fatiri].Fatirjeniskelamin << setw(12) << Fatirdaftar_pelanggan[Fatiri].Fatirnotelp << endl;
    }
    cin.get();
}