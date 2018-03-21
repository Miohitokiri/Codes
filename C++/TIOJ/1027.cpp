#include<bits/stc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, l, r, m;
	cin >> n;
	double data = 0;
	for ( int i = 0 ; i <= 50 ; i++ ){
		l = 0;
		r = 9;
		m = l + r;
		m >>= 1;
		while ( pow ( data, 2 ) != n ){
			data -= pow ( 10, -1 * i ) * m;
			m = l + r;
			m >>= 1;
			data += pow ( 10, -1 * i ) * m;
			if ( data > n )
				r = m;
			else if ( data < n )
				l = m;
			else if ( l == r )
				break;
		}
	}
	printf ( "%.50f\n", data );
}