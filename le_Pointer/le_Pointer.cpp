// le_Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

//Struktur LinkedList.
struct LNode{
	const static int l_value = 50; //panjang char-array
	char value[l_value+1]; //char-array dengan panjang l_value.
	struct LNode *next;
} *n_value,*head,*bind,*d_bind;

//Deklarasi fungsi-fungsi dan prosedur Stack untuk LinkedList:
void _init();			//Menginisialisasi pointer head;
void top();				//Menampilkan Stack paling atas;
int _count();			//Menghitung jumlah data dalam stack;
void fetch();			//Menampilkan semua;
void push_begin();		//Menambahkan data di depan;
bool delete_begin();	//Menghapus data di depan;
void clear();			//Membebaskan semua memori untuk LinkedList;

//Menu dengan tipe data char-array:
char menu[6][6] = {
	{"Top"},
	{"Push"},
	{"Pop"},
	{"Show"},
	{"Clear"},
	{"Quit"}
};
void fetch_menu();	//deklarasi fungsi untuk menampilkan ini var menu;

//Main function:
int main() {
	_init(); //Memanggil fungsi _init() untuk melakukan inisialisasi awal;
	char p; //deklarasi variabel p bertipe karakter untuk input user;
	do {
		//Membersihkan layar
		system("cls");
		//Menampilkan judul
		cout << "LinkedList\n";
		cout << "==========================\n";
		cout<<"Jumlah Data LinkedList : "<<_count()<<endl;	//Memanggil fungsi _count() untuk menampilkan jumlah LinkedList data.
		cout << "--------------------------\n";
		fetch_menu();										//Memanggil fungsi fetch_menu() untuk menampilkan menu;
		cout << "--------------------------\n";
		cout << "Pilihan : ";
		cin >> p;		//Input akan dimasukan ke variable p;
		cin.ignore();
		switch (p) { //pengalihan berdasarkan kondisi variable p
		case '1':top();break;			//nilai 1 untuk menampilkan data teratas;
		case '2':push_begin(); break;	//nilai 2 untuk menambah 1 data ke head linkedlist;
		case '3':delete_begin(); break;	//nilai 3 untuk menghapus 1 data linkedlist paling depan;
		case '4':fetch(); break;		//nilai 4 untuk menampilkan semua data linkedlist;
		case '5':clear(); break;		//nilai 5 untuk membebaskan semua memori untuk LinkedList;
		case '6':						//nilai 6 untuk keluar;
			cout << "Anda yakin ingin keluar ? (y/n) : ";
			cin >> p; //input p (konfirmasi);
			p = p == 'y' ? '6' : 'v'; //cek nilai p, jika 'y' maka nilai p akan diset menjadi 6 (keluar);
			break;
		default:						//Default atau jika pilihan tidak ditemukan
			cout << "Input tidak valid!";
			p = 'v'; //nilai aman;
			break;
		}
		system("PAUSE"); //Jeda;
	} while (p != '6'); //selama nilai variable p bukan 6;
}

//Implementasi prosedur untuk menampilkan isi variabel menu.
void fetch_menu() {
	/*
	looping selama value menu[i][0] bukan null,
	dimulai dari index 0 dimensi pertama dari var menu;
	*/
	for (int i = 0; (bool)menu[i][0] && menu[i][0] != 'X'; i++) {
		cout << i + 1 << " >> " << menu[i]<<endl; //menampilkan menu pada index i;
	}
}

//Implementasi fungsi untuk menampilkan jumlah data, dimulai dari head.
int _count() {
	int c = 0; //Variable untuk mengidentifikasi jumlah data;
	if (head == NULL) {
		c = 0;
	}
	else { //Jika head tidak kosong maka akan dilakukan penghitungan:
		bind = head;	//mengarahkan pointer bind ke head;
		/*
		c+=1 selama bind tidak null
		*/
		while (bind != NULL) {
			c++;
			bind = bind->next; //memajukan pointer bind;
		}
	}
	return c; //Mengembalikan nilai dari c;
}

//Implementasi prosedur untuk menjabarkan nilai LinkedList, dimulai dari head:
void fetch() {
	if (head == NULL) {  //Jika linked list kosong:
		cout << "LinkedList Kosong!"<<endl;
	}
	else { //Jika linked list tidak kosong:
		bind = head; //menunjukan pointer bind ke head;
		cout << "LinkedList Data(s) : \n";
		cout << "=============================================================================\n";
		cout <<setw(2)<<"|"<<setw(16) << "Address" << setw(2) << "|" << setw(50) << "Value" << setw(2)<<"\n";
		cout << "=============================================================================\n";
		//Perulangan untuk mengeluarkan semua data;
		while (bind!=NULL) {
			//cout << bind->value << " ";
			cout << setw(2) << "|" << setw(16) << &bind << setw(2) << "|" << setw(50) << bind->value << setw(2)<<"\n";
			bind = bind->next;
		}
		cout << endl; //newline;
	}
}

//Implementasi prosedur untuk meninisialisasi Stack:
void _init() {
	head = NULL;
}

//Implementasi prosedur untuk menampilkan data paling depan (data yang terakhir masuk):
void top(){
	if (head != NULL) { //jika head tidak null:
		cout<<"Top : "<<head->value; //menampilkan head->value;
	}
	else {
		cout << "Stack Kosong!";
	}
}

//Implementasi prosedur untuk mengalokasikan memori untuk n_value dan menyimpan input kedalam memori tersebut:
void create_new() {
	streamsize s = n_value->l_value; //indikasi s sebagai ukuran streamsize;
	string n_buff; //deklarasi string (user input);
	n_value = (LNode*)malloc(sizeof(struct LNode)); //mengalokasi memori untuk Node n_value;
	cout << "Masukan nilai ("<<s<<") : ";
	getline(cin,n_buff); //memindahkan input(cin) ke n_buff;
	cout << "Input : " << n_buff << endl; //menampilkan isi n_buff;
	if (n_buff.size() > s) { //jika buffer size n_buff melebihi ukuran s (streamsize);
		cout << "Input melebihi batas! Input akan dipangkas."<<endl;
		n_buff.resize(s); //resize ukuran n_buff sesuai nilai s;
	}
	cout <<"Input : "<<n_buff<<endl; //menampilkan isi n_buff setelah di-resize;
	strcpy_s(n_value->value, n_buff.c_str()); //menyalin n_buff ke n_value->value;
}

//Implementasi prosedur untuk mengaitkan n_value dengan head:
void push_begin() {
	create_new(); //memanggil prosedur create_new();
	if (head == NULL) {
		head = n_value; //mengarahkan pointer head ke n_value(alamat baru);
		head->next = NULL; //mengosongkan pointer next(pointer selanjutnya);
	}
	else {
		n_value->next = head; //menunjukan pointer n_value ke head (menggeser alamat head);
		head = n_value; //memasukan n_value ke pointer head (mendepankan n_value ke head);
		cout << "New Value : " << head->value; //menampilkan head;
	}
}

//Implementasi fungsi untuk menghapus node paling depan:
bool delete_begin() {
	if (head == NULL) {	//jika head == null:
		cout << "Kosong!";
		return false;		//mengembalikan nilai false;
	}
	else {
		d_bind = head;		//menunjukan pointer d_bind ke head;
		head=head->next;	//menunjukan pointer head ke pointer next;
		free(d_bind);		//membebaskan memori pointer d_bind;
		return true;		//mengembalikan nilai true;
	}
	return false; //mengembalikan nilai false secara default;
}

//Implementasi prosedur untuk menghapus semua node, dmulai dari node paling depan:
void clear(){
	/*
	eksekusi fungsi delete_begin() sampai mengembalikan nilai false;
	*/
	while (delete_begin()){
		cout << "Data terhapus!"<<endl; //tampil setiap iterasi;
	}
}