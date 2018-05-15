#include<iostream>

using namespace std;

inline int pow ( int a, int b ){
	int res = 1, base = a;
	while ( b ){
		if ( b & 1 ){
			res *= base;
			res %= 100;
		}

		base *= base;
		base %= 100;
		b >>= 1;
	}

	return res / 10;
}

int main(){
	int n;
	cin >> n;
	cout << pow ( 13, n ) << '\n';
}