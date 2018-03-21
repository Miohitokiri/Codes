#include<bits/stdc++.h>
using namespace std;
int dataN[7500000], dataM[7500000];
int n, m;
int findN ( int fi ){
	int l = 0, r = n - 1, mid;
	while ( dataN[mid] != fi ){
		mid = ( l + r ) / 2;
		if ( dataN[mid] > fi )
			r = mid;
		else
			l = mid;

		if ( l == r )
			break;
	}
	return mid;
}
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ )
		cin >> dataN[i];
	for ( int i = 0 ; i < n ; i++ )
		cin >> dataM[i];
	sort ( dataN, dataN + n );
	sort ( dataM, dataM + n );
	for ( int j = 0 ; j < m ; j++ ){
		if ( findN ( data[j] ) == 0 )
			continue;
		dataN[findN ( data[j] )] = 0;
	}
}