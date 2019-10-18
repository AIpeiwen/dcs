#include<iostream>
#include "Vector.cpp"
using namespace std;
int main() {
	Vector <int > a(20,0,0);
	a.insert(6);
	a.insert(3);
	a.insert(2);
	a.insert(7);
	a.insert(1);
	a.insert(5);
	a.insert(8);
	a.insert(4);

	cout << "ÅÅĞòÇ°" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[(Rank)i];
	}
	cout << endl;
	a.mergeSort(0,a.size());
	cout << "ÅÅĞòºó" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[(Rank)i];
	}
	cout << endl;
	return 0;
}