/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 02
*/

#include<iostream>
using namespace std;

int main()
{
	int Fatirn, *Fatirpn, **Fatirppn;
	Fatirn = 44;
	Fatirpn = &Fatirn;
	Fatirppn = &Fatirpn;
	cout << endl;
	cout << " Isi Variabel [Fatirn - *Fatirpn - *Fatirppn] = " << Fatirn <<" - "<<*Fatirpn<<" - " <<*Fatirppn<< endl;
	cout << "~~~~~~~~~" << endl;
	cout << endl;
	cout << " Alamat Variabel [&Fatirn - &Fatirpn - &Fatirppn] = " <<&Fatirn<<" - "<<*Fatirpn<<" - "<<*Fatirppn<< endl;
	cout << "~~~~~~~~~" << endl;
	cout << endl;
	cout << " isi Variabel dalam HEXA [Fatirn-Fatirpn-Fatirppn] = " <<Fatirn<<" - "<<Fatirpn<<" = "<<Fatirppn<< endl;
	cout << "~~~~~~~~~" << endl;
	cout << endl;
	cin.get();
}