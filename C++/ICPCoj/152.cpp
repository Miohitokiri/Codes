#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	double a, b, c, d;
	cin >> a >> b >> c >> d;
	a *= d, c *= b;
	a -= c;

	if ( a > 0 )
		cout << '>';
	else if ( a < 0 )
		cout << '<';
	else if ( a == 0 )
		cout << '=';
	cout << '\n';
}