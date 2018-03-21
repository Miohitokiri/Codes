#include<iostream>
using namespace std;
int main(){
	long long h, m;
	cin >> h >> m;
	h *= 60;
	m += h;
	cout << m << endl;
}