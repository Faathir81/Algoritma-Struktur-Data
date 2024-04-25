/* Faathir Akbar Nugroho
   4522210033
   kelas FatirA
   Algoritma & Struktur Data (Soal 01)
   Prak 12
*/
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

typedef struct Fatir_node 
{
    char* Fatirnama;
    char* Fatirdesc;
    struct Fatir_node* Fatirnext;
} Fatirnode;

#define FatirHASHSIZE 5
static Fatirnode* Fatirhashtab[FatirHASHSIZE];

void Fatirinithashtab() 
{
    for (int Fatiri = 0; Fatiri < FatirHASHSIZE; Fatiri++)
        Fatirhashtab[Fatiri] = NULL;
}

unsigned int FatirmyHash(char* Fatirs) 
{
    unsigned int Fatirh = 0;
    for (; *Fatirs; Fatirs++)
        Fatirh = *Fatirs + Fatirh * 31;
    return Fatirh % FatirHASHSIZE;
}

Fatirnode* Fatirlookup(char* Fatirn) 
{
    unsigned int Fatirhi = FatirmyHash(Fatirn);
    Fatirnode* Fatirnp = Fatirhashtab[Fatirhi];
    for (; Fatirnp != NULL; Fatirnp = Fatirnp->Fatirnext) 
	{
        if (!strcmp(Fatirnp->Fatirnama, Fatirn))
            return Fatirnp;
    }
    return NULL;
}

char* Fatirm_strdup(const char* Fatiro) {
    int Fatirl = strlen(Fatiro) + 1;
    char* Fatirns = (char*)malloc(Fatirl * sizeof(char));
    strcpy(Fatirns, Fatiro);
    if (Fatirns == NULL)
        return NULL;
    else
        return Fatirns;
}

char* get(const char* Fatirnama) 
{
    Fatirnode* Fatirn = Fatirlookup(const_cast<char*>(Fatirnama));
    if (Fatirn == NULL)
        return NULL;
    else
        return Fatirn->Fatirdesc;
}

int Fatirinstall(char* Fatirnama, char* Fatirdesc) 
{
    unsigned int Fatirhi = FatirmyHash(Fatirnama);
    Fatirnode* Fatirnp;
    if ((Fatirnp = Fatirlookup(Fatirnama)) == NULL) 
	{
        Fatirnp = (Fatirnode*)malloc(sizeof(Fatirnode));
        if (Fatirnp == NULL)
            return 0;
        Fatirnp->Fatirnama = Fatirm_strdup(Fatirnama);
        if (Fatirnp->Fatirnama == NULL)
            return 0;
        Fatirnp->Fatirnext = Fatirhashtab[Fatirhi];
        Fatirhashtab[Fatirhi] = Fatirnp;
    } 
	else
        free(Fatirnp->Fatirdesc);
    Fatirnp->Fatirdesc = Fatirm_strdup(Fatirdesc);
    if (Fatirnp->Fatirdesc == NULL)
        return 0;
    return 1;
}

void Fatirdisplaytable() 
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int Fatiri = 0; Fatiri < FatirHASHSIZE; Fatiri++) 
	{
        Fatirnode* Fatirt = Fatirhashtab[Fatiri];
        while (Fatirt != NULL) 
		{
            cout << "| " << setw(10) << left << Fatirt->Fatirnama << " |";
            cout << setw(12) << left << Fatirt->Fatirdesc << " |";
            cout << endl;
            Fatirt = Fatirt->Fatirnext;
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Fatircleanup() 
{
    Fatirnode* Fatirnp, * Fatirt;
    for (int Fatiri = 0; Fatiri < FatirHASHSIZE; Fatiri++) 
	{
        if (Fatirhashtab[Fatiri] != NULL) 
		{
            Fatirnp = Fatirhashtab[Fatiri];
            while (Fatirnp != NULL) 
			{
                Fatirt = Fatirnp->Fatirnext;
                free(Fatirnp->Fatirnama);
                free(Fatirnp->Fatirdesc);
                free(Fatirnp);
                Fatirnp = Fatirt;
            }
        }
    }
}

void Fatirdata() 
{
    int Fatiri;
    const char* Fatirnamas[] = {"nama ", "alamat ", "telpon ", "cita-cita ", "sekolah "};
    const char* Fatirdescs[] = {"Ichan", "Depok", "089999991", "Dosen", "Mahasiswa"};
    Fatirinithashtab();
    for (Fatiri = 0; Fatiri < 5; Fatiri++)
        Fatirinstall(const_cast<char*>(Fatirnamas[Fatiri]), const_cast<char*>(Fatirdescs[Fatiri]));
    cout << "Hasilnya adalah " << get("nama ") << " " << get("alamat ") << " " << get("telpon ") << " " << get("cita-cita ") << " " << get("sekolah ") << endl;
}

int main() 
{
    int Fatirpilihan;
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| nama || alamat || telpon || cita-cita || Sekolah ||" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "| MENU PILIHAN	|" << endl;
        cout << "~~~~~~~~~~~~~~~~" << endl;
        cout << "|1. Tampilan Data  |" << endl;
        cout << "|2. Display Table  |" << endl;
        cout << "|3. Cleanup        |" << endl;
        cout << "|4. Exit           |" << endl;
        cout << "| PILIHAN ANDA? [] |" << endl;
        cin >> Fatirpilihan;
        switch (Fatirpilihan) 
		{
            case 1:
                Fatirdata();
                break;
            case 2:
                Fatirdisplaytable();
                break;
            case 3:
                Fatircleanup();
                break;
            case 4:
                cout << "Terima Kasih! " << endl;
                break;
        }
        cin.get();
    } 
	while (Fatirpilihan != 4);
    return 0;
}