/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 03 (Nomor 26)
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    // Membuat queue untuk menyimpan nama OS
    queue<string> FatirosQueue;
    FatirosQueue.push("Maemo");
    FatirosQueue.push("Symbian");
    FatirosQueue.push("Mac");
    FatirosQueue.push("Windows");
    FatirosQueue.push("iPhone");

    // Memilih opsi perubahan dengan switch case
    char FatirOption;
	cout << "====================================================================="<<endl;
	cout << "a. memasukkan iPhone 5 diatas iPhone "<<endl;
	cout << "b. menambahkan Windows Phone diatas Windows"<<endl;
	cout << "c. menambahkan SnowLeopard setelah Mac"<<endl;
	cout << "d. menambahkan Symbian Belle setelah Symbian"<<endl;
	cout << "e. menambahkan Maemo 4 yang paling bawah tanpa menghilangkan semuanya"<<endl;
	cout << "====================================================================="<<endl;
	cout << "Masukkan opsi perubahan: ";
    cin >> FatirOption;
    switch (FatirOption) 
	{
        case 'a': 
		{
            // a. Memasukkan "iPhone 5" sebelum "iPhone"
            queue<string> FatirTempQueue;
            while (!FatirosQueue.empty()) 
			{
                if (FatirosQueue.front() == "iPhone") 
				{
                    FatirTempQueue.push("iPhone 5");
                }
                FatirTempQueue.push(FatirosQueue.front());
                FatirosQueue.pop();
            }
            FatirosQueue = FatirTempQueue;
            break;
        }
        case 'b': 
		{
            // b. Menambahkan "Windows Phone" sebelum "Windows"
            queue<string> FatirTempQueue;
            while (!FatirosQueue.empty()) 
			{
                if (FatirosQueue.front() == "Windows") 
				{
                    FatirTempQueue.push("Windows Phone");
                }
                FatirTempQueue.push(FatirosQueue.front());
                FatirosQueue.pop();
            }
            FatirosQueue = FatirTempQueue;
            break;
        }
        case 'c': 
		{
            // c. Menambahkan "SnowLeopard" setelah "Mac"
            queue<string> FatirTempQueue;
            while (!FatirosQueue.empty()) 
			{
                if (FatirosQueue.front() == "Mac") 
				{
                    FatirTempQueue.push(FatirosQueue.front());
                    FatirTempQueue.push("SnowLeopard");
                } 
				else 
				{
                    FatirTempQueue.push(FatirosQueue.front());
                }
                FatirosQueue.pop();
            }
            FatirosQueue = FatirTempQueue;
            break;
        }
        case 'd': 
		{
            // d. Menambahkan "Symbian Belle" setelah "Symbian"
            queue<string> FatirTempQueue;
            while (!FatirosQueue.empty()) 
			{
                if (FatirosQueue.front() == "Symbian") 
				{
                    FatirTempQueue.push(FatirosQueue.front());
                    FatirTempQueue.push("Symbian Belle");
                } 
				else 
				{
                    FatirTempQueue.push(FatirosQueue.front());
                }
                FatirosQueue.pop();
            }
            FatirosQueue = FatirTempQueue;
            break;
        }
        case 'e': 
		{
            // e. Menambahkan "Maemo 4" di paling bawah
            FatirosQueue.push("Maemo 4");
            break;
        }
		default:
        cout << "Opsi tidak valid." << endl;
        return 0;
    }

    // Mencetak isi queue setelah dimodifikasi
    while (!FatirosQueue.empty()) 
	{
        cout << FatirosQueue.front() << endl;
        FatirosQueue.pop();
    }

    return 0;
}