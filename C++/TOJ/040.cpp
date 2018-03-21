#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int a, b;
	while ( cin >> a >> b )
		cout << a / gcd ( a, b ) * b << '\n';
}