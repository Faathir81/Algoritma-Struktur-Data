/* Faathir Akbar Nugroho
   4522210033
   kelas A
   Algoritma & Struktur Data
   Prak 03 (Nomor 15)
*/
#include <iostream>
using namespace std;

// Membuat struktur node untuk linked list
struct Node {
  int FatirData;
  Node* FatirNext;
  Node* FatirPrev;
};

// Membuat fungsi untuk menampilkan isi dari linked list
void FatirDisplay(Node* FatirHead) 
{
  Node* FatirTemp = FatirHead;
  cout << "Data dalam linked list: ";
  do 
  {
    cout << FatirTemp->FatirData << " ";
    FatirTemp = FatirTemp->FatirNext;
  } 
  while (FatirTemp != FatirHead);
  cout << endl;
}

// Membuat fungsi untuk menyisipkan FatirData baru ke dalam linked list
void FatirInsert(Node** FatirHead_ref, int FatirNew_data) 
{
  // Mengalokasikan memori untuk node baru
  Node* new_node = new Node;
  new_node->FatirData = FatirNew_data;

  // Jika linked list masih kosong
  if (*FatirHead_ref == NULL) 
  {
    new_node->FatirNext = new_node;
    new_node->FatirPrev = new_node;
    *FatirHead_ref = new_node;
    return;
  }

  // Jika linked list tidak kosong
  Node* FatirLast = (*FatirHead_ref)->FatirPrev;
  new_node->FatirNext = *FatirHead_ref;
  (*FatirHead_ref)->FatirPrev = new_node;
  new_node->FatirPrev = FatirLast;
  FatirLast->FatirNext = new_node;
}

int main() {
  Node* FatirHead = NULL;

  // Menambahkan 8 buah FatirData ke dalam linked list
  FatirInsert(&FatirHead, 1);
  FatirInsert(&FatirHead, 2);
  FatirInsert(&FatirHead, 3);
  FatirInsert(&FatirHead, 4);
  FatirInsert(&FatirHead, 5);
  FatirInsert(&FatirHead, 6);
  FatirInsert(&FatirHead, 7);
  FatirInsert(&FatirHead, 8);

  // Menampilkan isi dari linked list
  FatirDisplay(FatirHead);

  // Menyisipkan FatirData baru bernilai 22 ke dalam linked list dengan inputan
  int FatirNew_data;
  cout << "Masukkan Data baru: ";
  cin >> FatirNew_data;
  FatirInsert(&FatirHead, FatirNew_data);

  // Menampilkan isi dari linked list setelah FatirData baru disisipkan
  FatirDisplay(FatirHead);

  cin.get();
}