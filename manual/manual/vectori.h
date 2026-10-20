#pragma once
#include <iostream>
using namespace std;

//PROBLEME MANUAL PG 32

//1.
void solutie1() {
	int v[100] = { 2,16,19,5,23,98,34,17};
	int n = 8;

	int aux = v[0];
	for (int i = 1;i < n / 2;i++) {
		v[i-1] = v[i];
	}
	v[(n / 2) - 1] = aux;
	aux = v[n - 1];
	for (int i = n - 2;i >= n / 2;i--) {
		v[i + 1] = v[i];
	}
	v[n / 2] = aux;

	for (int i = 0;i < n;i++) {
		cout << v[i] << " ";
	}

}

//2.
void solutie2() {
	long long n = 5231678;
	int f[10] = {0};

	while (n != 0) {
		int cif = n % 10;
		f[cif]++;
		n = n / 10;
	}
	cout << "a) ";
	for (int i = 9;i >= 0;i--) {
	 	int aux = f[i];
		while (aux != 0) {
			cout << i;
			aux--;
		}
	}
	cout << endl;
	cout << "b) ";
	for (int i = 9;i >= 0;i--) {
		if (f[i] != 0) {
			cout << i;
		}
	}

}

//3.
void solutie3() {
	int v[100] = { 6,24,87,35,76,87,95,80,9,37,97,78,34 };
	int d = 13;
	int f[101]{};

	for (int i = 0;i < d;i++) {
		f[v[i]]++;
	}

	for (int i = 0;i < 100;i++) {
		while (f[i] != 0) {
			cout << i << " ";
			f[i]--;
		}
	}

}

//4.
void solutie4() {
	int v[100] = { 6,24,24,87,0,35,76,87,95,80,9 };
	int d = 11;
	int f[101]{};

	for (int i = 0;i < d;i++) {
		f[v[i]]++;
	}

	for (int i = 0;i < 100;i++) {
		if (f[i] != 0) {
			cout << i << " ";
		}
	}
}

//5.
void solutie5() {
	int v[100] = { 2,12,17,32,12,32,17,9,13 };
	int d = 9;
	int fprim[101]{};
	int fultim[101]{};

	for (int i = 0;i < d;i++) {
		if (fprim[v[i]] == 0) {
			fprim[v[i]] = i + 1;
		}
		fultim[v[i]] = i + 1;
	}

	for (int i = 0;i <= 100;i++) {
		if (fprim[i] != 0) {
			cout << i << " " << fultim[i] - fprim[i] << endl;
		}
	}

}

//6.
void solutie6() {
	int v[1000] = { 12,17,32,83,16,63,87 };
	int d = 7;

	for (int i = 0;i < d;i++) {
		if (v[i] % 2 == 0) {
			for (int j = d;j > i + 1;j--) {
				v[j] = v[j - 1];
			}
			d++;
			v[i + 1] = 2019;
		}

	}

	for (int i = 0;i < d;i++) {
		cout << v[i] << " ";
	}

}

//7.
void solutie7() {
	int v[501] = { 12,17,32,32,16,63,63,87 };
	int d = 7;

	for (int i = 0;i < d - 1;i++) {
		if (v[i] == v[i + 1]) {
			for (int j = i + 1;j < d - 1;j++) {
				v[j] = v[j + 1];
			}
			d--;
			i--;
		}
	}

	for (int i = 0;i < d;i++) {
		cout << v[i] << " ";
	}

}

//8.
void solutie8() {
	int v[501] = { 1,3,4,5,6,12,16,32 };
	int d = 8;
	int x = d;
	int rez = -1;

	for (int i = d - 1;i >= 0;i--) {
		if (v[i] <= x) {
			cout << v[i];
			rez = 1;
			break;
		}
	}

	if (rez == -1) {
		cout << "nu exista.";
	}

}

void solutie8alternativ() {
	int v[501] = { 1,3,4,5,6,12,16,32 };
	int d = 8;
	int x = d;
	int ls = 0;int ld = d - 1;
	bool ok = 0;
	int rez = 0;

	while (ls <= ld) {
		int mij = (ls + ld) / 2;
		if (v[mij] <= x) {
			ok = 1;
			rez = v[mij];
			ls = mij + 1;
		}
		else {
			ld = mij - 1;
		}
	}

	if (ok) {
		cout << rez;
	}
	else {
		cout << "nu exista.";
	}

}

//9.
void solutie9() {
	int m = 6;
	int a[501] = {12,16,18,21,25,32};
	int n = 5;
	int b[501] = {3,9,17,22,37};
	bool ok = 0;
	int i = m - 1;
	int j = n - 1;

	while (i >= 0 && j >= 0) {
		if (a[i] >= b[j]) {
			if (a[i] % 2 != 0) {
				cout << a[i] << " ";
				ok = true;
			}
			i--;
		}
		else {
			if (b[j] % 2 != 0) {
				cout << b[j] << " ";
				ok = true;
			}
			j--;
		}	
	}

	while (i >= 0) {
		if (a[i] % 2 != 0) {
			cout << a[i] << " ";
			ok = true;
		}
		i--;
	}

	while (j >= 0) {
		if (b[j] % 2 != 0) {
			cout << b[j] << " ";
			ok = 1;
		}
		j--;
	}

	if (ok == false) {
		cout << "nu exista";
	}

}

//PROBLEMA BAC

//Două numere distincte se numesc în oglindă dacă fiecare dintre ele se 
// obține prin citirea cifrelor celuilalt de la dreapta la stânga. 
// Exemplu: 127 și 721 sunt în oglindă, iar pentru numerele 100 sau 121 nu există niciun
// număr cu care să fie în oglindă. Scrieți un program C / C++ care citește de la tastatură 
// un număr natural n (n∈[2, 50]), apoi cele n elemente ale unui tablou unidimensional, 
// numere naturale din intervalul[0, 104). Programul transformă tabloul în memorie înlocuind
// fiecare element de trei cifre cu numărul cu care el este în oglindă, dacă acesta există, ca în exemplu. 
// Elementele tabloului obținut sunt afișate pe ecran, separate prin câte un spațiu,
// iar dacă nu s - a înlocuit niciun element se afișează pe ecran mesajul nu exista.
// Exemplu: pentru n = 9 și tabloul (721, 72, 6, 108, 180, 1221, 121, 537, 1000), se obține tabloul 
// (127, 72, 6, 801, 180, 1221, 121, 735, 1000). iar pentru n = 4 și tabloul (525, 72, 6, 120),
// se afișează pe ecran mesajul nu exista.

void solutieBAC()
{
	int n;
	int v[51];
	cin >> n;
	int vf = 0;

	for (int i = 0;i < n;i++) {
		cin >> v[i];
		int aux = v[i];
		int ct = 0, ogl = 0;
		while (aux != 0) {
			int cif = aux % 10;
			ogl = ogl * 10 + cif;
			ct++;
			aux = aux / 10;
		}

		if (ct == 3 && v[i]%10!=0 && ogl != v[i]) {
			v[i] = ogl;
			vf = 1;
		}
	}

	if (vf == 0) {
		cout << "nu exista" << endl;
	}
	else {
		for (int i = 0;i < n;i++) {
			cout << v[i] << " ";
		}
	}


}
