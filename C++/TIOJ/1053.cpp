#include<iostream>
using namespace std;
int main(){
	int p, q;
	cin >> p >> q;
	( p % q == 0 || q % p == 0 ) ? cout << "Y\n" : cout << "N\n";
}