/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 03 (Nomor 6)
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FatirPelanggan 
{
	public:
		string Fatirnama;
		string Fatiralamat;
		int Fatirumur;
		char FatirjenisKelamin;
		string Fatirnotelp;
		
		void Fatirinput() 
		{
			cout << "Nama\t\t\t: ";
			cin >> Fatirnama;
			cout << "Alamat\t\t\t: ";
			cin >> Fatiralamat;
			cout << "Umur\t\t\t: ";
			cin >> Fatirumur;
			cout << "Jenis Kelamin (L/P)\t: ";
			cin >> FatirjenisKelamin;
			cout << "No. Telp\t\t: ";
			cin >> Fatirnotelp;
		}
		
		void FatirtampilData() 
		{
			cout << setw(10) << Fatirnama << setw(15) << Fatiralamat << setw(10) << Fatirumur << setw(10) << FatirjenisKelamin << setw(15) << Fatirnotelp << endl;
		}
};

int main() 
{
    int FatirjumlahPelanggan;

    cout << "Masukkan jumlah pelanggan: ";
    cin >> FatirjumlahPelanggan;

    FatirPelanggan daftarPelanggan[FatirjumlahPelanggan];

    for (int Fatiri = 0; Fatiri < FatirjumlahPelanggan; Fatiri++) 
	{
        cout << "\nData pelanggan ke-" << Fatiri+1 << endl;
        daftarPelanggan[Fatiri].Fatirinput();
    }
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                    Data Pelanggan Toko" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(10) << "Nama" << setw(15) << "Alamat" << setw(10) << "Umur" << setw(10) << "JK" << setw(15) << "No. Telp" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int Fatiri = 0; Fatiri < FatirjumlahPelanggan; Fatiri++) 
	{
        daftarPelanggan[Fatiri].FatirtampilData();
    }
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    return 0;
}