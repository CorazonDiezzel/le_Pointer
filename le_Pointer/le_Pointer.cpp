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
struct LinkedList{
	const static int l_value = 50;
	char value[l_value+1];
	struct LinkedList *next;
} *n_value,*head,*bind,*d_bind;

//Deklarasi fungsi-fungsi Stack untuk LinkedList.
void _init();			//Menginisialisasi pointer head;
void top();				//Menampilkan Stack paling atas;
int _count();			//Menghitung jumlah data dalam stack.
void fetch();			//Menampilkan semua 
void push_begin();		//Menambahkan data di depan.
bool delete_begin();	//Menghapus data di depan.
void clear();			//Membebaskan semua memori untuk LinkedList.

//Menu
char menu[6][6] = {
	{"Top"},
	{"Push"},
	{"Pop"},
	{"Show"},
	{"Clear"},
	{"Quit"}
};
void fetch_menu();

//Main function.
int main() {
	_init();
	char p;
	do {
		system("cls");
		cout << "LinkedList\n";
		cout << "==========================\n";
		cout<<"Jumlah Data LinkedList : "<<_count()<<endl;
		cout << "--------------------------\n";
		fetch_menu();
		cout << "--------------------------\n";
		cout << "Pilihan : ";
		cin >> p;
		switch (p) {
		case '1':
			cout << "Top : ";top();
		break;
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
			_getche();
			break;
		}
		_getche();
	} while (p != '6');
}

void fetch_menu() {
	for (int i = 0; (bool)menu[i][0]; i++) {
		cout << i + 1 << " >> " << menu[i]<<endl;
	}
}
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
void fetch() {
	if (head == NULL) {
		cout << "LinkedList Kosong!"<<endl;
	}
	else {
		bind = head;
		cout << "LinkedList Data(s) : ";
		while (bind !=NULL) {
			cout << bind->value << " ";
			bind = bind->next;
		}
		cout << endl;
	}
}
void _init() {
	head = NULL;
}
void top(){
	if (head != NULL) {
		cout<<head->value;
	}
	else {
		cout << "Stack Kosong!";
	}
}

void create_new() {
	streamsize s = n_value->l_value;
	string n_buff;
	n_value = (LinkedList*)malloc(sizeof(struct LinkedList));
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
	_getche();
}
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
		_getche();
	}
}
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
void clear() {
	while (delete_begin()) {
		cout << "Data terhapus!"<<endl;
	}
}