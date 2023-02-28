
#include <iostream>
#include "LinkedList.h"

using namespace std;

struct runs {
	int km, minute;
};

struct runner {
	string name;
	int totalrun;
	float av;
	LinkedList<runs> myList;
}p[20];

int main() {
	int count, i, j;
	float sumkm = 0, summin = 0;
	
	string name;
	int totalrun, km, minute;
	runs rr;

	cout << "How many runner information will you enter: ";
	cin >> count;
	for (i = 0; i < count; i++) {
		cout << "\nName of the Runner " << i + 1 << ":";
		cin >> name;
		cout << "How many previous run does " << name << " have : ";
		cin >> totalrun;
		cout << "Enter " << name << "'s scores\n";
		cout << "------------------------------------------\n";
		p[i].name = name;
		p[i].totalrun = totalrun;
		

		for (j = 0; j < totalrun; j++) {
			cout << "Run " << j + 1 << ":";
			cout << "Distance(km) :";
			cin >> km;
			cout << "Running Time(minutes) :";
			cin >> minute;
			rr.km = km;
			rr.minute = minute;
			(p[i]).myList.insertLast(rr);
		}
	}
	
	for (i = 0; i < count; i++) {
		sumkm = 0;
		summin = 0;
		cout << (p[i].name) << "'s Runs:\n";
		for (j = 0; j < p[i].totalrun; j++) {
			rr = p[i].myList.front();
			p[i].myList.deleteFirst();
			cout << "Distance(km) :" << rr.km << "  \tRunning Time(minutes) :" << rr.minute << "\n";
			sumkm = sumkm + rr.km;
			summin = summin + rr.minute;
		}
		p[i].av = summin / sumkm;

	}

	for (i = 0; i < count; i++) {
		cout << (p[i].name) << "'s best average running time for 1 km: " << p[i].av << "\n";
	}

} 
