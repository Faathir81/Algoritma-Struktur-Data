/* Faathir Akbar Nugroho
   4522210033
   kelas FatirA
   Algoritma & Struktur Data (Soal 02)
   Prak 11
*/
#include <iostream>
using namespace std;

struct Fatirnode
{
    int Fatirinfo;
    struct Fatirnode *Fatirnext;
};

class Fatirstack
{
    struct Fatirnode *Fatirtop;
	public:
		Fatirstack();
		void Fatirpush(int);
		int Fatirpop();
		bool FatirisEmpty();
		void Fatirdisplay();
};

Fatirstack::Fatirstack()
{
    Fatirtop = NULL;
}

void Fatirstack::Fatirpush(int Fatirdata)
{
    Fatirnode *Fatirp;
    if ((Fatirp = (Fatirnode*)malloc(sizeof(Fatirnode))) == NULL)
    {
        cout << "Memori Penuh";
        exit(0);
    }
    Fatirp = new Fatirnode;
    Fatirp->Fatirinfo = Fatirdata;
    Fatirp->Fatirnext = NULL;
    if (Fatirtop != NULL)
    {
        Fatirp->Fatirnext = Fatirtop;
    }
    Fatirtop = Fatirp;
}

int Fatirstack::Fatirpop()
{
    struct Fatirnode *Fatirtemp;
    int Fatirvalue;
    if (Fatirtop == NULL)
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        Fatirtemp = Fatirtop;
        Fatirtop = Fatirtop->Fatirnext;
        Fatirvalue = Fatirtemp->Fatirinfo;
        delete Fatirtemp;
    }
    return Fatirvalue;
}

bool Fatirstack::FatirisEmpty()
{
    return (Fatirtop == NULL);
}

void Fatirstack::Fatirdisplay()
{
    struct Fatirnode *Fatirp = Fatirtop;
    if (Fatirtop == NULL)
    {
        cout << "Tidak ada tampilan " << endl;
    }
    else
    {
        cout << "Isi Stack: ";
        while (Fatirp != NULL)
        {
            cout << Fatirp->Fatirinfo << " ";
            Fatirp = Fatirp->Fatirnext;
        }
        cout << endl;
    }
}

class FatirGraph
{
	private:
		int Fatirn;
		int **FatirA;
	public:
		FatirGraph(int Fatirsize = 2);
		~FatirGraph();
		bool FatirisConnected(int, int);
		void FatiraddEdge(int Fatirx, int Fatiry);
		void FatirDFS(int Fatirx, int required);
};

FatirGraph::FatirGraph(int Fatirsize)
{
    int Fatiri, Fatirj;
    if (Fatirsize < 2)
        Fatirn = 2;
    else
        Fatirn = Fatirsize;
    FatirA = new int *[Fatirn];
    for (Fatiri = 0; Fatiri < Fatirn; ++Fatiri)
        FatirA[Fatiri] = new int[Fatirn];
    for (Fatiri = 0; Fatiri < Fatirn; ++Fatiri)
        for (Fatirj = 0; Fatirj < Fatirn; ++Fatirj)
            FatirA[Fatiri][Fatirj] = 0;
}

FatirGraph::~FatirGraph()
{
    for (int Fatiri = 0; Fatiri < Fatirn; ++Fatiri)
        delete[] FatirA[Fatiri];
    delete[] FatirA;
}

bool FatirGraph::FatirisConnected(int Fatirx, int Fatiry)
{
    return (FatirA[Fatirx - 1][Fatiry - 1] == 1);
}

void FatirGraph::FatiraddEdge(int Fatirx, int Fatiry)
{
    FatirA[Fatirx - 1][Fatiry - 1] = FatirA[Fatiry - 1][Fatirx - 1] = 1;
}

void FatirGraph::FatirDFS(int Fatirx, int required)
{
    Fatirstack Fatirs;
    bool *Fatirvisited = new bool[Fatirn + 1];
    int Fatiri;
    for (Fatiri = 0; Fatiri <= Fatirn; Fatiri++)
        Fatirvisited[Fatiri] = false;
    Fatirs.Fatirpush(Fatirx);
    Fatirvisited[Fatirx] = true;
    if (Fatirx == required)
        return;
    cout << "Depth First Search - FatirDFS - Awal Vertex = " << Fatirx << endl;
    while (!Fatirs.FatirisEmpty())
    {
        int Fatirk = Fatirs.Fatirpop();
        if (Fatirk == required)
            break;
        cout << Fatirk << " ";
        for (Fatiri = Fatirn; Fatiri >= 1; --Fatiri)
            if (FatirisConnected(Fatirk, Fatiri) && !Fatirvisited[Fatiri])
            {
                Fatirs.Fatirpush(Fatiri);
                Fatirvisited[Fatiri] = true;
            }
    }
    cout << endl;
    delete[] Fatirvisited;
}

int main()
{
    FatirGraph Fatirg(8);
    Fatirg.FatiraddEdge(1, 2);
    Fatirg.FatiraddEdge(1, 3);
    Fatirg.FatiraddEdge(1, 4);
    Fatirg.FatiraddEdge(2, 5);
    Fatirg.FatiraddEdge(3, 6);
    Fatirg.FatiraddEdge(4, 7);
    Fatirg.FatiraddEdge(4, 8);
    Fatirg.FatirDFS(1, 8);
    return 0;
}