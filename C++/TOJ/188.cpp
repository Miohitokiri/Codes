#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int pow ( int c, int n, int p){
	if ( n == 0 )
		return 1;
	int t = pow ( c, n / 2, p );
	if ( n % 2 == 0)
		return t * t % p;
	else
		return t * t % p * c % p;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define ine long long

	int c, n, p;
	while ( cin >> c >> n >> p )
		cout << pow ( c, n, p ) << '\n';
}