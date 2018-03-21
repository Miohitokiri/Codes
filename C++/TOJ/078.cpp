#include<bits/stdc++.h>
#define l first
#define r second

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	pair < int, int > data[1000005];
	int n, L, R;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i].l >> data[i].r;

	sort ( data, data + n );

	L = data[0].l, R = data[0].r;
	for ( int i = 1 ; i < n ; i++ )
		if ( R < data[i].l ){
			cout << L << ' ' << R << '\n';
			L = data[i].l, R = data[i].r;
		}
		else
			R = max ( R, data[i].r );

	cout << L << ' ' << R << '\n';
}