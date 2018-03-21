#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n;
	double stop, a, b, x;
	cin >> n >> x >> a >> b;
	b /= a;
	bool ans = false;
	while ( n-- ){
		cin >> stop;
		if ( x / stop == b ){
			ans = true;
			break;
		}
	}

	cout << ( ans ? "Yes" : "No" ) << '\n';
}