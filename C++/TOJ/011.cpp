#include<bits/stdc++.h>
using namespace std;
int data[2000005], stop[2000005];
long long ans;
inline void mergeSort ( int l, int r ){
	if ( l == r )
		return ;
	int m = ( l + r ) / 2, p = l, q = m + 1, index = l;

	mergeSort ( l, m );
	mergeSort ( m + 1, r );

	while ( p <= m || q <= r ){
		if ( p <= m && ( q > r || data[p] <= data[q] ) )
			stop[index++] = data[p++];
		else{
			ans += ( m - p + 1 );
			stop[index++] = data[q++];
		}
	}

	memcpy ( data + l, stop + l, sizeof ( int ) * ( r - l + 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	cin >> n;
	ans = 0;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];

	mergeSort ( 0, n - 1 );

	cout << ans << '\n';
}