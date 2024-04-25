/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Contoh 1)
   Prak 10
*/
#include <iostream>
using namespace std;

struct FatirCanBTree 
{
    int *Fatird;
    FatirCanBTree **FatirCanAnakPointer;
    bool Fatirl;
    int Fatirn;
} *Fatirr = NULL, *Fatirnp = NULL, *Fatirx = NULL, *Fatirnpl = NULL, *Fatirnp3 = NULL, *Fatiry = NULL;

FatirCanBTree* Fatirinit() 
{
    int Fatiri;
    Fatirnp = new FatirCanBTree;
    Fatirnp->Fatird = new int[6];
    Fatirnp->FatirCanAnakPointer = new FatirCanBTree *[7];
    Fatirnp->Fatirl = true;
    Fatirnp->Fatirn = 0;
    for (Fatiri = 0; Fatiri < 7; Fatiri++) 
	{
        Fatirnp->FatirCanAnakPointer[Fatiri] = NULL;
    }
    return Fatirnp;
}

void FatirpohonB(FatirCanBTree *Fatirp) 
{
    cout << endl;
    int Fatiri;
    for (Fatiri = 0; Fatiri < Fatirp->Fatirn; Fatiri++) 
	{
        if (Fatirp->Fatirl == false) 
		{
            FatirpohonB(Fatirp->FatirCanAnakPointer[Fatiri]);
        }
        cout << " " << Fatirp->Fatird[Fatiri];
    }
    if (Fatirp->Fatirl == false) 
	{
        FatirpohonB(Fatirp->FatirCanAnakPointer[Fatiri]);
    }
}

void FatirUrut(int *Fatirp, int Fatirn) 
{
    int Fatiri, Fatirj, Fatirt;
    for (Fatiri = 0; Fatiri < Fatirn; Fatiri++) 
	{
        for (Fatirj = Fatiri; Fatirj <= Fatirn; Fatirj++) 
		{
            if (Fatirp[Fatiri] > Fatirp[Fatirj]) 
			{
                Fatirt = Fatirp[Fatiri];
                Fatirp[Fatiri] = Fatirp[Fatirj];
                Fatirp[Fatirj] = Fatirt;
            }
        }
    }
}

int FatirPecahAnak(FatirCanBTree *Fatirx, int Fatiri) 
{
    int Fatirj, Fatirmid;
    FatirCanBTree *Fatiry;
    Fatirnp3 = Fatirinit();
    Fatirnp3->Fatirl = true;
    if (Fatiri == -1) 
	{
        Fatirmid = Fatirx->Fatird[2];
        Fatirx->Fatird[2] = 0;
        Fatirx->Fatirn--;
    }
    return Fatirmid;
}

void FatirSisip(int Fatira) 
{
    int Fatiri, Fatirj, Fatirt, Fatirmid;
    Fatirx = Fatirr;
    if (Fatirx == NULL) 
	{
        Fatirr = Fatirinit();
        Fatirx = Fatirr;
    } 
	else 
	{
        if (Fatirx->Fatirl == true && Fatirx->Fatirn == 6) 
		{
            Fatirt = FatirPecahAnak(Fatirx, -1);
            Fatirx = Fatirr;
            for (Fatiri = 0; Fatiri < (Fatirx->Fatirn); Fatiri++) 
			{
                if ((Fatira > Fatirx->Fatird[Fatiri]) && (Fatira < Fatirx->Fatird[Fatiri + 1])) 
				{
                    Fatiri++;
                    break;
                } 
				else
				{					
					if (Fatira < Fatirx->Fatird[0]) 
					{
						break;
					} 	
					else 
					{
						continue;
					}
				}
            }
            Fatirx = Fatirx->FatirCanAnakPointer[Fatiri];
        } 
		else 
		{
            while (Fatirx->Fatirl == false) 
			{
                for (Fatiri = 0; Fatiri < (Fatirx->Fatirn); Fatiri++) 
				{
                    if ((Fatira > Fatirx->Fatird[Fatiri]) && (Fatira < Fatirx->Fatird[Fatiri + 1])) 
					{
                        Fatiri++;
                        break;
                    } 
					else 
					{
						if (Fatira < Fatirx->Fatird[0]) 
						{
							Fatirnpl = Fatirinit();
							Fatirnpl->Fatirl = false;
							Fatirx->Fatirl = true;
							for (Fatirj = 3; Fatirj < 6; Fatirj++) 
							{
								Fatirnp3->Fatird[Fatirj - 3] = Fatirx->Fatird[Fatirj];
								Fatirnp3->FatirCanAnakPointer[Fatirj - 3] = Fatirx->FatirCanAnakPointer[Fatirj];
								Fatirnp3->Fatirn++;
								Fatirx->Fatird[Fatirj] = 0;
								Fatirx->Fatirn--;
							}
							Fatirmid = Fatirx->Fatird[2];
							Fatirx->Fatird[2] = 0;
							Fatirx->Fatirn--;
							for (Fatirj = 0; Fatirj < 6; Fatirj++) 
							{
								Fatirx->FatirCanAnakPointer[Fatirj] = NULL;
							}	
							Fatirnpl->Fatird[0] = Fatirmid;
							Fatirnpl->FatirCanAnakPointer[Fatirnpl->Fatirn] = Fatirx;
							Fatirnpl->FatirCanAnakPointer[Fatirnpl->Fatirn + 1] = Fatirnp3;
							Fatirnpl->Fatirn++;
							Fatirr = Fatirnpl;
						} 
						else 
						{
							Fatiry = Fatirx->FatirCanAnakPointer[Fatiri];
							Fatirmid = Fatiry->Fatird[2];
							Fatiry->Fatird[2] = 0;
							Fatiry->Fatirn--;
							Fatirx->FatirCanAnakPointer[Fatiri + 1] = Fatiry;
							Fatirx->FatirCanAnakPointer[Fatiri + 1] = Fatirnp3;
							break;
						}
					}
				}
                if (Fatiri == Fatirx->Fatirn) 
				{
                    Fatirx = Fatirx->FatirCanAnakPointer[Fatiri];
                }
				if ((Fatirx->FatirCanAnakPointer[Fatiri])->Fatirn == 6) 
				{
                    Fatirt = FatirPecahAnak(Fatirx, 1);
                    Fatirx->Fatird[Fatirx->Fatirn] = Fatirt;
                    Fatirx->Fatirn++;
                    continue;
                } 
				else 
				{
                    Fatirx = Fatirx->FatirCanAnakPointer[Fatiri];
                }
            }
        }
    }
    Fatirx->Fatird[Fatirx->Fatirn] = Fatira;
    FatirUrut(Fatirx->Fatird, Fatirx->Fatirn);
    Fatirx->Fatirn++;
}

int main() 
{
    int Fatiri, Fatirn, Fatirt;
    cout << "Masukkan Jumlah Elemen Yang Akan Diinput: ";
    cin >> Fatirn;
    cout << endl;
    for (Fatiri = 0; Fatiri < Fatirn; Fatiri++) 
	{
        cout << "Masukkan Isi Elemen: ";
        cin >> Fatirt;
        FatirSisip(Fatirt);
    }
    cout << endl;
    cout << endl;
    cout << "HASIL PENGURUTAN MENGGUNAKAN BTREE" << endl;
    cout << "~~~~~~~~~~~~" << endl;
    FatirpohonB(Fatirr);
    cout << endl;
	return 0;
}