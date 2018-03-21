#include<bits/stdc++.h>

using namespace std;

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return a > b ? b : a;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, son, mother;
	while ( cin >> n ){
		son = n / 2;
		mother = n - son;
		while ( gcd ( mother, son ) != 1 )
			mother++, son--;

		cout << son << ' ' << mother << '\n';
	}
}