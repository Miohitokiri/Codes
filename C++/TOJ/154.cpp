#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair < long long, long long > pii;

bool cmp ( pii a, pii b ){
	if ( a.x == b.x )
		return a.y < b.y;
	return a.x > b.x;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long t, n, ans, stop;
	vector < pii > work;
	cin >> t;
	while ( t-- ){
		work.clear();
		ans = 0;
		cin >> n;
		for ( int i = 1 ; i <= n ; i++ ){
			cin >> stop;
			work.push_back ( make_pair ( stop, i ) );
		}

		sort ( work.begin(), work.end(), cmp );

		for ( int i = 0 ; i < n ; i++ )
			ans += work[i].x * ( i + 1 );

		printf ( "%lld", work[0].y );
		for ( int i = 1 ; i < n ; i++ )
			printf ( " %lld", work[i].y );
		printf ( "\n%lld\n", ans );
	}
}