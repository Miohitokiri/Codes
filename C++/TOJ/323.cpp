#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

int b[100005], dp[100005], n, m;
pair < int, int > a[100005];

inline int bin ( int x ){
	int l = 1, r = n, mid;
	while ( l != r ){
		mid = l + r >> 1;
		if ( a[mid].x < x )
			l = mid + 1;
		else
			r = mid;
	}

	return a[r].y;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> a[i].x;
		a[i].y = i;
	}

	sort ( a + 1, a + 1 + n );

	while ( m-- ){
		memset ( dp, 0x3f, sizeof ( dp ) );
		for ( int i = 0 ; i < n ; i++ )
			cin >> b[i];

		for ( int i: b ){
			int x = bin ( i );
			*lower_bound ( dp, dp + n, x ) = x;
		}

		cout << lower_bound ( dp, dp + n, 0x3f3f3f3f ) - dp << '\n';
	}
}