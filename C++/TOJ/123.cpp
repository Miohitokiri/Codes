#include<iostream>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	 
	int n;
	cin >> n;
	 
	string in, out;
	cin >> out >> in;
	 
	bool ans = false;
	for ( int i = 0 ; i < n && !ans ; i++ )
		if ( in[i] == '0' ) {
			if ( i - 1 >= 0 && out[i - 1] == '0' )
				ans = true;
			if ( out[i] == '0' )
				ans = true;
			if ( i + 1 < n && out[i + 1] == '0' )
				ans = true;
		}
	 
	 cout << ( ans ? "FENESTRATION FORTIFICATION FAILURE!" : "FENDED OFF!" ) << '\n';
}