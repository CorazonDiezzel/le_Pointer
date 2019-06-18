// le_Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
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
	char p; //deklarasi variabel p bertipe char untuk input user;
	do {
		system("cls");
		cout << "LinkedList\n";
		cout << "==========================\n";
		cout<<"Jumlah Data LinkedList : "<<_count()<<endl;	//Memanggil fungsi _count() untuk menampilkan jumlah LinkedList data.
		cout << "--------------------------\n";
		fetch_menu();										//Memanggil fungsi fetch_menu() untuk menampilkan menu;
		cout << "--------------------------\n";
		cout << "Pilihan : ";
		cin >> p;		//Input akan dimasukan ke variable p;
		cin.ignore();
		switch (p) {
		case '1':top();break;
		case '2':push_begin(); break;
		case '3':delete_begin(); break;
		case '4':fetch(); break;
		case '5':clear(); break;
		case '6':
			cout << "Anda yakin ingin keluar ? (y/n) : ";
			cin >> p;
			p = p == 'y' ? '6' : p;
			break;
		default:
			cout << "Input tidak valid!";
			p = 'v';
			break;
		}
		system("PAUSE");
	} while (p != '6');
}

//Implementasi prosedur untuk menampilkan isi variabel menu.
void fetch_menu() {
	/*
	looping selama value menu[i][0] bukan null,
	dimulai dari index 0 dimensi pertama dari var menu;
	*/
	for (int i = 0; (bool)menu[i][0]; i++) {
		cout << i + 1 << " >> " << menu[i]<<endl; //menampilkan menu pada index i;
	}
}

//Implementasi fungsi untuk menampilkan jumlah data, dimulai dari head.
int _count() {
	int c = 0;
	if (head == NULL) {
		c = 0;
	}
	else {
		bind = head;
		while (bind != NULL) {
			c++;
			bind = bind->next;
		}
	}
	return c;
}

//Implementasi prosedur untuk menjabarkan nilai LinkedList, dimulai dari head.
void fetch() {
	if (head == NULL) {
		cout << "LinkedList Kosong!"<<endl;
	}
	else {
		bind = head;
		cout << "LinkedList Data(s) : ";
		while (bind!=NULL) {
			cout << bind->value << " ";
			bind = bind->next;
		}
		cout << endl;
	}
}

//Implementasi prosedur untuk meninisialisasi Stack.
void _init() {
	head = NULL;
}

//Implementasi prosedur untuk menampilkan data paling depan (data yang terakhir masuk).
void top(){
	if (head != NULL) {
		cout<<"Top : "<<head->value;
	}
	else {
		cout << "Stack Kosong!";
	}
}

//Implementasi prosedur untuk mengalokasikan memori untuk n_value dan menyimpan input kedalam memori tersebut.
void create_new() {
	streamsize s = n_value->l_value;
	string n_buff;
	n_value = (LNode*)malloc(sizeof(struct LNode));
	cout << "Masukan nilai ("<<s<<") : ";
	cin.ignore();
	getline(cin,n_buff);
	cout << "Input : " << n_buff << endl;
	if (n_buff.size() > s) {
		cout << "Input melebihi batas! Input akan dipangkas."<<endl;
		n_buff.resize(s);
	}
	cout <<"Input : "<<n_buff<<endl;
	strcpy_s(n_value->value, n_buff.c_str());
}

//Implementasi prosedur untuk mengaitkan n_value dengan head.
void push_begin() {
	create_new();
	if (head == NULL) {
		head = n_value;
		head->next = NULL;
	}
	else {
		n_value->next = head;
		head = n_value;
		cout << "New Value : " << head->value;
	}
}

//Implementasi prosedur untuk menghapus node paling depan;
bool delete_begin() {
	if (head == NULL) {
		cout << "Kosong!";
		return false;
	}
	else {
		d_bind = head;
		head=head->next;
		free(d_bind);
		return true;
	}
	return false;
}

//Implementasi prosedur untuk menghapus semua node, dmulai dari node paling depan;
void clear(){
	while (delete_begin()){
		cout << "Data terhapus!"<<endl;
	}
}