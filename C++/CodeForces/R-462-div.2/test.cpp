#include<bits/stdc++.h>

using namespace std;

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

int main(){
	int a, b;
	while ( cin >> a >> b )
		cout << gcd ( a, b ) << '\n';
}
