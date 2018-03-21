#include<iostream>

using namespace std;

inline int winner ( int l, int k ){
	int g = 0;
	for ( int i = 1 ; i <= l ; i++ )
		g = ( g + k ) % i;

	return g + 1;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m;
	cin >> n >> m;
	cout << winner ( n, m ) << '\n';
}