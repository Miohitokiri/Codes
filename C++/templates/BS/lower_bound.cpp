// lower _bound
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	cin >> n;
	int data[100];
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];
	sort ( data, data + n );
	int l = 0, r = n - 1, mid = ( l + r ) / 2, q;
	cin >> q;
	while ( data[mid] != q ){
		mid = ( l + r ) / 2;
		if ( data[mid] > q )
			r = mid;
		else if ( data[mid] < q )
			l = mid;
		if ( r == l )
			break;
	}
	cout << data[mid] << '\n';
}