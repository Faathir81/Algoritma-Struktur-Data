/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 03
*/

#include <iostream>
using namespace std;

struct FatirMahasiswa 
{
	char FatirNPM [9];
	char Fatirnama [30];
	float Fatiripk;
};
int main ()
{
	FatirMahasiswa Fatirmhs;
	cout << "Nomor Pokok Mahasiswa    = " ; cin >> Fatirmhs.FatirNPM;
	cout << "Nama Mahasiswa           = " ; cin >> Fatirmhs.Fatirnama;
	cout << "Indek Prestasi komulatif = " ; cin >> Fatirmhs.Fatiripk;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "    Data Anda" << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Nomor Pokok Mahasiswa    = " << Fatirmhs.FatirNPM << endl;
	cout << "Nama Mahasiswa           = " << Fatirmhs.Fatirnama << endl;
	cout << "Indek Prestasi komulatif = " << Fatirmhs.Fatiripk << endl;
	cin.get();
}