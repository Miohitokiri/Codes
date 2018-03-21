#include<iostream>
using namespace std;
int main(){
	long long m, h = 0;
	cin >> m;
	h += ( m - m % 60 ) / 60;
	m %= 60;
	cout << h << " " << m << endl;
	return 0;
}