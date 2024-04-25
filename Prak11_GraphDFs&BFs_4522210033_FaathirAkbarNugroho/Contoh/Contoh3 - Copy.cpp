/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 3)
   Prak 11
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Fatirq[20], Fatirtop = -1, Fatirfront = -1, Fatirrear = -1, Fatira[20][20], Fatirvis[20], Fatirstack[20];

int Fatirdel();
void Fatiradd(int Fatiritem);
void Fatirbfs(int Fatirs, int Fatirn);
void Fatirdfs(int Fatirs, int Fatirn);
void Fatirpush(int Fatiritem);
int Fatirpop();

int main()
{
	int Fatirn, Fatiri, Fatirs, Fatirch, Fatirj;
	cout << "Masukkan Jumlah Data: ";
	cin >> Fatirn;

	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		for (Fatirj = 1; Fatirj <= Fatirn; Fatirj++)
		{
			cout << "Masukkan Data " << Fatiri << " Jika Mempunyai Simpul " << Fatirj << ", Selain itu: ";
			cin >> Fatira[Fatiri][Fatirj];
		}
	}

	cout << "Matriks Adjacency" << endl;
	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		for (Fatirj = 1; Fatirj <= Fatirn; Fatirj++)
		{
			cout << Fatira[Fatiri][Fatirj] << ' ';
		}
		cout << endl;
	}

	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		Fatirvis[Fatiri] = 0;
		cout << "  MENU " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1. BFS - Breadth First Search" << endl;
		cout << "2. DFS - Depth First Search" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Pilihan: ";
		cin >> Fatirch;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Masukkan Simpul Sumber: ";
		cin >> Fatirs;
		switch (Fatirch)
		{
			case 1: Fatirbfs(Fatirs, Fatirn);
				break;
			case 2: Fatirdfs(Fatirs, Fatirn);
				break;
			case 3:
				break;
		}
	}
	return 0;
}

void Fatirbfs(int Fatirs, int Fatirn)
{
	int Fatirp, Fatiri;
	Fatiradd(Fatirs);
	Fatirvis[Fatirs] = 1;
	Fatirp = Fatirdel();
	if (Fatirp != 0)
		cout << Fatirp << "  ";
	while (Fatirp != 0)
	{
		for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
		{
			if ((Fatira[Fatirp][Fatiri] != 0) && (Fatirvis[Fatiri] == 0))
			{
				Fatiradd(Fatiri);
				Fatirvis[Fatiri] = Fatiri;
			}
		}
		Fatirp = Fatirdel();
		if (Fatirp != 0)
			cout << Fatirp << "  ";
	}
	for (Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		if (Fatirvis[Fatiri] == 0)
			Fatirbfs(Fatiri, Fatirn);
	}
}

void Fatiradd(int Fatiritem)
{
	if (Fatirrear == 19)
	{
		cout << "Antrian Penuh" << endl;
		cout << "~~~~~~~~~~~~~" << endl;
	}
	else
	{
		if (Fatirrear == -1)
		{
			Fatirq[++Fatirrear] = Fatiritem;
			Fatirfront++;
		}
		else
		{
			Fatirq[++Fatirrear] = Fatiritem;
		}
	}
}

int Fatirdel()
{
	int Fatirk, Fatirn;
	Fatirpush(Fatirfront);
	Fatirvis[Fatirfront] = 1;
	Fatirk = Fatirpop();
	if (Fatirk != 0)
		cout << Fatirk << "  ";
	while (Fatirk != 0)
	{
		for (int Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
		{
			if ((Fatira[Fatirk][Fatiri] != 0) && (Fatirvis[Fatiri] == 0))
			{
				Fatirpush(Fatiri);
				Fatirvis[Fatiri] = 1;
			}
		}
		Fatirk = Fatirpop();
		if (Fatirk != 0)
			cout << Fatirk << "  ";
	}
	for (int Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		if (Fatirvis[Fatiri] == 0)
			Fatirdfs(Fatiri, Fatirn);
	}
}

void Fatirpush(int Fatiritem)
{
	if (Fatirtop == 19)
		cout << "Stack Overflow" << endl;
	else
		Fatirstack[++Fatirtop] = Fatiritem;
}

int Fatirpop()
{
	int Fatirk;
	if (Fatirtop == -1)
		return (0);
	else
	{
		Fatirk = Fatirstack[Fatirtop--];
		return (Fatirk);
	}
}

void Fatirdfs(int Fatirs, int Fatirn)
{
	Fatirpush(Fatirs);
	Fatirvis[Fatirs] = 1;
	cout << Fatirs << " ";

	for (int Fatiri = 1; Fatiri <= Fatirn; Fatiri++)
	{
		if (Fatira[Fatirs][Fatiri] && !Fatirvis[Fatiri])
			Fatirdfs(Fatiri, Fatirn);
	}
}