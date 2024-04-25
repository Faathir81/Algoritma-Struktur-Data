/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 01
*/

#include <iostream>
#include <string>
using namespace std;

int main()
//Deklarasi STRUKTUR
{
	struct fatirMATAKULIAH
	{
		string fatirnama;
		int fatirsks;
		char fatirnhuruf;
		float fatirnangka;
	};
//Pendefinisian STRUKTUR
	fatirMATAKULIAH fatirData_MK;
//Pengaksesan anggota struktur
	fatirData_MK.fatirnama = "Algoritma dan Pemrograman 2";
	fatirData_MK.fatirsks = 3;
	fatirData_MK.fatirnhuruf = 'A';
	fatirData_MK.fatirnangka = 4.00;
	cout<<endl;
	cout<<endl;
	cout<<"Mata Kuliah = "<<fatirData_MK.fatirnama<<endl;
	cout<<"Jumlah sks  = "<<fatirData_MK.fatirsks<<endl;
	cout<<"Nilai       = "<<fatirData_MK.fatirnhuruf<<endl;
	cout<<"Indeks      = "<<fatirData_MK.fatirnangka<<endl;
	cin.get();
}