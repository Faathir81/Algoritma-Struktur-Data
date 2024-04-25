/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 06
*/
#include <iostream>
using namespace std;
int Fatira[50];
void Fatirmerge (int,int,int);
void Fatirmerge_sort (int Fatirlow, int Fatirhigh)
{
	int Fatirmid;
	if (Fatirlow<Fatirhigh)
	{
		Fatirmid = (Fatirlow+Fatirhigh)/2;
		Fatirmerge_sort(Fatirlow, Fatirmid);
		Fatirmerge_sort(Fatirmid+1, Fatirhigh);
		Fatirmerge(Fatirlow,Fatirmid,Fatirhigh);
	}
}
void Fatirmerge(int Fatirlow, int Fatirmid, int Fatirhigh)
{
	int Fatirh, Fatiri, Fatirj, Fatirb[50], Fatirk;
	Fatirh = Fatirlow;
	Fatiri = Fatirlow;
	Fatirj = Fatirmid+1;
	while ((Fatirh<=Fatirmid)&&(Fatirj<=Fatirhigh))
	{
		if(Fatira[Fatirh]<=Fatira[Fatirj])
		{
			Fatirb[Fatiri]=Fatira[Fatirh];
			Fatirh++;
		}
		else
		{
			Fatirb[Fatiri]=Fatira[Fatirj];
			Fatirj++;
		}
		Fatiri++;
	}
	if (Fatirh>Fatirmid)
	{
		for(Fatirk=Fatirj; Fatirk<=Fatirhigh; Fatirk++)
		{
			Fatirb[Fatiri]=Fatira[Fatirk];
			Fatiri++;
		}
	}
	else
	{
		for (Fatirk=Fatirh; Fatirk<=Fatirmid; Fatirk++)
		{
			Fatirb[Fatiri]=Fatira[Fatirk];
			Fatiri++;
		}
	}
	for (Fatirk=Fatirlow; Fatirk<=Fatirhigh; Fatirk++)
	{
		Fatira[Fatirk]=Fatirb[Fatirk];
	}
}
int main()
{
	int Fatirnum, Fatiri;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "MERGE SORT PROGRAM" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "Masukkan Banyak Bilangan : "; cin >> Fatirnum;
	cout << endl;
	cout << "Sekarang masukkan " << Fatirnum << " Bilangan yang ingin diurutkan" << endl;
	for (Fatiri=1; Fatiri<=Fatirnum; Fatiri++)
	{
		cout << "Bilangan ke-" << Fatiri << " "; cin >> Fatira[Fatiri];
	}
	Fatirmerge_sort(1,Fatirnum); 
	cout << endl;
	cout << "Hasil akhir pengurutan :" << endl;
	cout << endl;
	for (Fatiri=1; Fatiri<=Fatirnum; Fatiri++)
	{
		cout << Fatira[Fatiri] << " ";
	}
	cout << endl;
	cin.get();
}