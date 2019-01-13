// merge sort
#include<bits/stdc++.h>
using namespace std;

int data[8], stop[8];
inline void mergeSort ( int l, int r ){
	if ( l == r )
		return ;

	int m = ( l + r ) / 2, p = l, q = m + 1, index = l;

	mergeSort ( l, m );
	mergeSort ( m + 1, r );
	
	while ( p <= m || q <= r )
		if ( p <= m && ( q > r || data[p] <= data[q] ) )
			swap ( stop[index++], data[p++] );
		else
			swap ( stop[index++], data[q++] );
	
	memcpy ( data + l, stop + l, sizeof ( int ) * ( r - l + 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	for ( int i = 0 ; i < 8 ; i++ )
		cin >> data[i];

	mergeSort ( 0, 7 );

	for ( int i = 0 ; i < 8 ; i++ )
		cout << data[i] << ' ';
	cout << '\n';
}