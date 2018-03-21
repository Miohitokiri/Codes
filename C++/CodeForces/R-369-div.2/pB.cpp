#include<bits/stdc++.h>

using namespace std;

long long data[505][505], n, ans = -1, a[505], b[505], x, y, l, r;


int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	bool check = true;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < n ; j++ ){
			cin >> data[i][j];
			if ( !data[i][j] )
				x = i, y = j;
		}

	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < n ; j++ ){
			a[i] += data[i][j];
			b[j] += data[i][j];
		}
		l += data[i][i];
		r += data[i][n - i - 1];
	}

	for ( int i = 1 ; i < n && check ; i++ ){
		check = ( a[i] == a[i - 1] && i != x && i - 1 != x );
		check = ( b[i] == b[i - 1] && i != y && i - 1 != y );
	}

	if ( check ){
	}
}