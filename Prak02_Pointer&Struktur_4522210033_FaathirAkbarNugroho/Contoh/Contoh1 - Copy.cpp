/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 02
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	int Fatiri;
	char *FatirnamaKu, FatirNM[8]={'F','A','A','T','H','I','R'};
	cout<<"Nama KU"<<endl;
	cout<<"~~~"<<endl;
	for(Fatiri=0;Fatiri<8;Fatiri++)
	{
		FatirnamaKu = &FatirNM[Fatiri];
		cout<<" "<<*FatirnamaKu<<endl;
	}
	cin.get();
}