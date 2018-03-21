#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int x, v, l, n;
	double t = 0;

	cin >> l >> n;
	while ( n-- ){
		cin >> x >> v;
		if ( v > 0 )
			t = max ( t, ( double ) ( ( l - x ) / v ) );
		else
			t = max ( t, ( double ) ( ( l - x ) / ( -v ) ) );
	}
	printf ( "%.3f\n", t );
}