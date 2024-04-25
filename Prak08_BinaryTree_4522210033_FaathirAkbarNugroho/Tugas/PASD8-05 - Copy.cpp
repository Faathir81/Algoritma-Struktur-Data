/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data (Soal 05)
   Prak 08
*/
#include <iostream>
#include <string>
using namespace std;

struct FatirNode 
{
    string Fatirdata;
    FatirNode* Fatirleft;
    FatirNode* Fatirright;
};

FatirNode* FatircreateNode(string Fatirdata) 
{
    FatirNode* FatirnewNode = new FatirNode();
    if (FatirnewNode) 
	{
        FatirnewNode->Fatirdata = Fatirdata;
        FatirnewNode->Fatirleft = FatirnewNode->Fatirright = NULL;
    }
    return FatirnewNode;
}

FatirNode* FatirinsertNode(FatirNode* Fatirroot, string Fatirdata) 
{
    if (Fatirroot == NULL) 
	{
        Fatirroot = FatircreateNode(Fatirdata);
        return Fatirroot;
    }

    if (Fatirdata < Fatirroot->Fatirdata)
        Fatirroot->Fatirleft = FatirinsertNode(Fatirroot->Fatirleft, Fatirdata);

    else if (Fatirdata >= Fatirroot->Fatirdata)
        Fatirroot->Fatirright = FatirinsertNode(Fatirroot->Fatirright, Fatirdata);

    return Fatirroot;
}

void FatirinorderTraversal(FatirNode* Fatirroot) 
{
    if (Fatirroot == NULL)
        return;

    FatirinorderTraversal(Fatirroot->Fatirleft);
    cout << Fatirroot->Fatirdata << " ";
    FatirinorderTraversal(Fatirroot->Fatirright);
}

int main() 
{
    FatirNode* Fatirroot = NULL;
    int Fatirchoice;
    string Fatirdata;

    do 
	{
        cout << "Menu:\n";
        cout << "1. Input Integer/String\n";
        cout << "2. Cetak\n";
        cout << "3. Input String/Float\n";
        cout << "4. Cetak\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> Fatirchoice;

        switch (Fatirchoice) 
		{
            case 1:
                cout << "Masukkan Integer/String: ";
                cin >> Fatirdata;
                Fatirroot = FatirinsertNode(Fatirroot, Fatirdata);
                break;
            case 2:
                cout << "Cetak Binary Tree secara Inorder: ";
                FatirinorderTraversal(Fatirroot);
                cout << endl;
                break;
            case 3:
                cout << "Masukkan String/Float: ";
                cin >> Fatirdata;
                Fatirroot = FatirinsertNode(Fatirroot, Fatirdata);
                break;
            case 4:
                cout << "Cetak Binary Tree secara Inorder: ";
                FatirinorderTraversal(Fatirroot);
                cout << endl;
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
        }
    } 
	while (Fatirchoice != 5);

    return 0;
}