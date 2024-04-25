/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 12
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cctype>
#define FatirHASHSIZE 100
#define FatirKODEMK 30
#define FatirNAMAMK 13
using namespace std;

struct FatirHashData 
{
	char Fatirkode[FatirKODEMK];
	char Fatirnama[FatirNAMAMK];
};

static FatirHashData *FatirhashTable[FatirHASHSIZE];

void FatirClear();
void Fatirinsert(FatirHashData *);
void Fatirsearching(FatirHashData *);
int FatirsearchingProcess(FatirHashData *, int);
void Fatirdeleting(FatirHashData *);
bool FatirisIndexEmpty(int);
int FatircharacterAmount(char []);
int FatirhashFunction(FatirHashData *Fatirarray); // Deklarasikan fungsi FatirhashFunction di sini
void FatirDisplayTable();


int main() {
	char Fatirulang = 'Y', Fatirmenu;
	do {
		system("cls");
		puts("	PROSES HASH TABLE	");
		puts("");
		puts("1. Input");
		puts("2. Delete");
		puts("3. Find");
		puts("4. Display");
		puts("5. Clear");
		puts("x. Keluar");
		puts("");
		cout << "MENU PILIHAN ANDA : ";
		cin >> Fatirmenu;

		switch (Fatirmenu) {
			case '1':
				FatirHashData *Fatirarray;
				Fatirarray = new FatirHashData;
				puts("");
				cout << "KodeMK		: ";
				cin >> Fatirarray->Fatirkode;
				cout << "MataKuliah	: ";
				cin >> Fatirarray->Fatirnama;
				cout << endl;
				Fatirinsert(Fatirarray);
				break;
			case '2':
				FatirHashData *Fatirhapus;
				Fatirhapus = new FatirHashData;
				cout << "Hapus MataKuliah (kodeMK) ";
				cin >> Fatirhapus->Fatirkode;
				Fatirdeleting(Fatirhapus);
				break;
			case '3':
				FatirHashData *Fatircari;
				Fatircari = new FatirHashData;
				cout << "Cari MataKuliah (KodeMK) : ";
				cin >> Fatircari->Fatirkode;
				Fatirsearching(Fatircari);
				break;
			case '4':
				FatirDisplayTable();
				break;
			case '5':
				FatirClear();
				puts("Table hash telah dikosongkan.");
				break;
			case 'x':
			case 'X':
				Fatirulang = 'T';
				break;
			default:
				puts("Pilihan diluar Fatirmenu yang tersedia");
				break;
		}
		cin.get();
	} while (toupper(Fatirulang) == 'Y');
}

void FatirClear() {
	for (int Fatiri = 0; Fatiri < FatirHASHSIZE; Fatiri++)
		FatirhashTable[Fatiri] = NULL;
}

void Fatirinsert(FatirHashData *Fatirarray) {
	int Fatirrec;
	Fatirrec = FatirhashFunction(Fatirarray);
	FatirhashTable[Fatirrec] = Fatirarray;
	cout << "Input Succesfully!" << endl;
	cout << "Data disimpan pada record indeks " << Fatirrec << endl;
	cin.get();
}

void Fatirsearching(FatirHashData *Fatircari) {
	int Fatirrec;
	Fatirrec = FatirhashFunction(Fatircari);
	Fatirrec = FatirsearchingProcess(Fatircari, Fatirrec);
	if (Fatirrec >= 0) {
		cout << "Data ditemukan pada record indeks " << Fatirrec << endl;
		cout << "Isi data	 " << endl;
		cout << "=> KodeMK     :\t" << FatirhashTable[Fatirrec]->Fatirkode << endl;
		cout << "=> MataKuliah :\t" << FatirhashTable[Fatirrec]->Fatirnama << endl;
	} else
		cout << "Maaf! Data tidak ditemukan." << endl;
	cin.get();
}

int FatirsearchingProcess(FatirHashData *Fatircari, int Fatirrec) {
	int Fatirm, Fatirn, Fatirj = 0;
	bool Fatirequal = true;
	if (FatirisIndexEmpty(Fatirrec) == false) 
	{
		Fatirn = FatircharacterAmount(Fatircari->Fatirkode);
		Fatirm = FatircharacterAmount(FatirhashTable[Fatirrec]->Fatirkode);
		if (Fatirn == Fatirm) 
		{
			while ((Fatirequal == true) && (Fatircari->Fatirkode[Fatirj] != '\0')) 
			{
				if (tolower(Fatircari->Fatirkode[Fatirj]) != tolower(FatirhashTable[Fatirrec]->Fatirkode[Fatirj]))
					Fatirequal = false;
					Fatirj++;
			}
			if (Fatirequal == true)
				return Fatirrec;
			else
				return -1;
		} 
		else
			return -1;
	} 
	else
		return -1;
	cin.get();
}

void Fatirdeleting(FatirHashData *Fatirhapus) {
	int Fatirrec;
	Fatirrec = FatirhashFunction(Fatirhapus);
	Fatirrec = FatirsearchingProcess(Fatirhapus, Fatirrec);
	if (Fatirrec >= 0) {
		cout << "Data : " << endl;
		cout << "=> KodeMK     :\t" << FatirhashTable[Fatirrec]->Fatirkode << endl;
		cout << "=> MataKuliah :\t" << FatirhashTable[Fatirrec]->Fatirnama << endl;
		cout << "terhapus!" << endl;
		FatirhashTable[Fatirrec] = NULL;
	} else
		cout << "Maaf Data tidak ditemukan!" << endl;
	cin.get();
}

int FatirhashFunction(FatirHashData *Fatirarray) {
	int Fatirvalue = 0, Fatirrec, Fatirn;
	Fatirn = FatircharacterAmount(Fatirarray->Fatirkode);
	for (int Fatiri = 0; Fatiri < Fatirn; Fatiri++)
		Fatirvalue += Fatirarray->Fatirkode[Fatiri];
	Fatirrec = Fatirvalue % FatirHASHSIZE;
	return Fatirrec;
}

bool FatirisIndexEmpty(int Fatirrec) {
	if (FatirhashTable[Fatirrec] == NULL)
		return true;
	else
		return false;
}

int FatircharacterAmount(char Fatirarray[]) {
	int Fatirjumlah = 0;
	for (int Fatiri = 0; Fatirarray[Fatiri] != '\0'; Fatiri++)
		Fatirjumlah++;
	return Fatirjumlah;
}

void FatirDisplayTable() {
	cout << endl;
	cout << "|~~~~~~~~|~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	cout << "| Indeks |   KODEMK   |    Nama Mata Kuliah     |" << endl;
	cout << "|~~~~~~~~|~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	for (int Fatiri = 0; Fatiri < FatirHASHSIZE; Fatiri++) {
		if (FatirisIndexEmpty(Fatiri) == false) 
			cout << setw(6) << Fatiri << "          " << FatirhashTable[Fatiri]->Fatirkode << "\t	" << FatirhashTable[Fatiri]->Fatirnama << endl;
	}
	cin.get();
}