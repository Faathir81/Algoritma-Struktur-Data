/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 2)
   Prak 11
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Fatira[10][20], Fatirq[20], Fatirvisited[20], Fatirn, Fatiri, Fatirj, Fatirf = 0, Fatirr = -1;

void Fatirbfs(int Fatirv)
{
	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		if (Fatira[Fatirv][Fatiri] && !Fatirvisited[Fatiri])
			Fatirq[++Fatirr] = Fatiri;
	}

	if (Fatirf <= Fatirr)
	{
		Fatirvisited[Fatirq[Fatirf]] = 1;
		Fatirbfs(Fatirq[Fatirf++]);
	}
}

int main()
{
	int Fatirv;
	cout << "Masukkan Jumlah Vertex: ";
	cin >> Fatirn;

	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		Fatirq[Fatiri] = 0;
		Fatirvisited[Fatiri] = 0;
	}

	cout << "Masukkan Data Graph Dalam Bentuk Matriks [nxn]: " << endl;
	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		for (Fatirj = 1; Fatirj <= Fatirn; Fatirj++)
		{
			cin >> Fatira[Fatiri][Fatirj];
		}
	}

	cout << "Masukkan Vertex Awal: ";
	cin >> Fatirv;
	Fatirbfs(Fatirv);

	cout << "Node Yang Dapat Dicapai: ";
	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		if (Fatirvisited[Fatiri])
			cout << Fatiri << " ";
		else
		{
			cout << "BFS - Tidak Semua Node Dapat Dijangkau";
			break;
		}
	}
	cout << endl;

	cin.ignore();
	cin.get();
	return 0;
}