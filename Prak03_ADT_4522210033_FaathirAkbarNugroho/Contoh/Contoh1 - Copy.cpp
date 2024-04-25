/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 03
*/
#include <iostream>
#include <string>
using namespace std;

typedef int Fatirangka;
typedef float Fatirpecahan;
typedef char Fatirhuruf[30];
int main()
{
	Fatirangka Fatirumur;
	Fatirpecahan Fatirpecah;
	Fatirhuruf Fatirnama;
	Fatirhuruf Fatirkarakter;
	cout<<"Masukkan umur anda         : ";cin>>Fatirumur;
	cout<<"Umur anda adalah           : "<<Fatirumur<<endl;
	cout<<endl;
	cout<<"Masukkan bilangan pecahan  : ";cin>>Fatirpecah;
	cout<<"Bilangan pecahan           : "<<Fatirpecah<<endl;
	cout<<endl;
	cout<<"Masukkan nama              : ";cin>>Fatirnama;
	cout<<"Nama anda                  : "<<Fatirnama<<endl;
	cout<<endl;
	cout<<"Masukkan satu huruf        : ";cin>>Fatirkarakter;
	cout<<"Huruf anda                 : "<<Fatirkarakter<<endl;
	cin.get();
}