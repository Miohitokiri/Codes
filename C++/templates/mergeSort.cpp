// merge sort
#include<bits/stdc++.h>
using namespace std;

int data[8], swp[8];

// basic version
void mergeSort ( int l, int r ){
	if ( l == r )
		return ;

	int m = ( l + r ) / 2, p = l, q = m + 1, idx = l;

	mergeSort ( l, m );
	mergeSort ( m + 1, r );
	
	while ( p <= m && q <= r )
		if ( p <= m && data[p] <= data[q] )
			swp[idx++] = data[p++];
		else
			swp[idx++] = data[q++];

	while ( p <= m )
		swp[idx++] = data[p++];

	while ( q <= r )
		swp[idx++] = data[q++];

	for ( int i = l ; i <= r ; i++ )
		data[i] = swp[i];
}

// advanced version
void mergeSort2 ( int l, int r ){
	if ( l == r )
		return ;

	int m = ( l + r ) / 2, p = l, q = m + 1, index = l;

	mergeSort2 ( l, m );
	mergeSort2 ( m + 1, r );
	
	while ( p <= m || q <= r )
		if ( p <= m && ( q > r || data[p] <= data[q] ) )
			swap ( swp[index++], data[p++] );
		else
			swap ( swp[index++], data[q++] );
	
	memcpy ( data + l, swp + l, sizeof ( int ) * ( r - l + 1 ) );
	// memcpy ( 想要複製的位置ptr, 來源ptr, size );
	// memcpy ( data, swp, sizeof ( data ) );
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
