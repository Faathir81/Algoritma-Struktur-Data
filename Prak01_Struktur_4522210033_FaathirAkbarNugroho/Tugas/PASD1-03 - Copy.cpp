/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 01 (Nomor 3)
*/
#include <iostream>
#include <string>
using namespace std;

struct FatirKTP 
{
    string FatirNIK, FatirNama, FatirAlamat, FatirAgama, FatirStatusPerkawinan, FatirPekerjaan, FatirKewarganegaraan, FatirMasaBerlaku;
    int FatirTahunLahir;
    char FatirJenisKelamin;
};

void tampilanKTP(FatirKTP FatirKTP) 
{
    cout << "NIK               : " << FatirKTP.FatirNIK << endl;
    cout << "Nama              : " << FatirKTP.FatirNama << endl;
    cout << "Alamat            : " << FatirKTP.FatirAlamat << endl;
    cout << "Tahun Lahir       : " << FatirKTP.FatirTahunLahir << endl;
    cout << "Jenis Kelamin     : " << FatirKTP.FatirJenisKelamin << endl;
    cout << "Agama             : " << FatirKTP.FatirAgama << endl;
    cout << "Status Perkawinan : " << FatirKTP.FatirStatusPerkawinan << endl;
    cout << "Pekerjaan         : " << FatirKTP.FatirPekerjaan << endl;
    cout << "Kewarganegaraan   : " << FatirKTP.FatirKewarganegaraan << endl;
    cout << "Masa Berlaku KTP  : " << FatirKTP.FatirMasaBerlaku << endl;
}

int main() 
{
    FatirKTP Fatir;
    cout << "Masukkan NIK              : "; getline(cin, Fatir.FatirNIK);
    cout << "Masukkan Nama             : "; getline(cin, Fatir.FatirNama);
    cout << "Masukkan Alamat           : "; getline(cin, Fatir.FatirAlamat);
	cout << "Masukkan Tahun Lahir      : "; cin >> Fatir.FatirTahunLahir;
    cout << "Masukkan Jenis Kelamin (L/P): "; cin >> Fatir.FatirJenisKelamin;
    cout << "Masukkan Agama            : "; cin.ignore(); getline(cin, Fatir.FatirAgama); 
	cout << "Masukkan Status Perkawinan: "; getline(cin, Fatir.FatirStatusPerkawinan);
    cout << "Masukkan Pekerjaan        : "; getline(cin, Fatir.FatirPekerjaan);
	cout << "Masukkan Kewarganegaraan  : "; getline(cin, Fatir.FatirKewarganegaraan);
    cout << "Masukkan Masa Berlaku KTP : "; getline(cin, Fatir.FatirMasaBerlaku);
    cout << endl << "KTP Anda:" << endl;
	tampilanKTP(Fatir);
    cin.get();
}