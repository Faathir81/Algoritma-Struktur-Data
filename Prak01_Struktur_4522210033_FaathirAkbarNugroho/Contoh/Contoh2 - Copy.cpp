/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 01
*/

#include <iostream>
#include <string>
using namespace std;

//Deklarasi STRUKTUR
struct fatirKoordinat
{
	int fatirX;
	int fatirY;
};
//Prototipe
void fatirTampil_Posisi(fatirKoordinat fatirPosisi);

int main()
{
//Pendefinisian variabel STRUKTUR
	fatirKoordinat fatirPosisi;
//Pengaksesan anggota struktur
	fatirPosisi.fatirX = 56;
	fatirPosisi.fatirY = 53;
	cout<<endl;
	fatirTampil_Posisi(fatirPosisi);
	cin.get();
}

//Definisi fungsi fatirTampil_Posisi
void fatirTampil_Posisi(fatirKoordinat fatirPosisi)
{
	cout<<"Posisi Ordinat X adalah "<<fatirPosisi.fatirX<<endl;
	cout<<"Posisi Ordinat Y adalah "<<fatirPosisi.fatirY<<endl;
}