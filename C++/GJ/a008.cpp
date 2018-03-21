#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double C;
	cin >> C;
	double F = C * 9 / 5 + 32;
	cout << fixed << setprecision ( 1 ) << F << endl;
}