/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 4)
   Prak 02
*/

#include<iostream>
using namespace std;

struct Node
{
	int FatirNilaiUTS;
	int FatirNilaiUAS;
	int FatirN1, FatirN2;
};
Node *FatirP, *FatirQ;

int main()
{
	FatirP = new Node;
	FatirP -> FatirN1 = 99;
	FatirQ = new Node;
	FatirQ -> FatirN2 = 78;
	//Menampilkan isi variabel
	cout<<endl;
	cout<<"Isi Variabel FatirP = "<<FatirP -> FatirN1<<endl;
	cout<<"Isi Variabel FatirQ = "<<FatirQ -> FatirN2<<endl;
	cout<<endl;
	cin.get();
}