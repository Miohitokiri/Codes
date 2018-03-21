#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, t;
	cin >> t;
	while ( t-- ){
		cin >> a >> b;
		while ( a % b && b % a )
			a > b ? a %= b : b %= a;
		cout << min ( a, b ) << '\n';
	}
}