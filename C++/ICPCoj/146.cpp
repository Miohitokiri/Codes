#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int x, y;
	double m;
	cin >> x >> y;
	m = ( double ) x / y;
	if ( m == ( int ) m )
		cout << m;
	else
		cout << ( int ) m + 1;
	cout << '\n';
}