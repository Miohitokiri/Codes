#include<bits/stdc++.h>

using namespace std;

#define int long long

struct casE{
	int t, k, d;
	casE ( int a, int b, int c ): t ( a ), k ( b ), d ( c ) {}
};

bool cmp ( casE a, casE b ){
	return a.t < b.t;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, t, k, d, server[105];
	vector < casE > data;
	cin >> n >> m;
	while ( m-- ){
		cin >> t >> k >> d;
		data.push_back ( casE ( t, k, d ) );
	}

	sort ( data.begin(), data.end(), cmp );
	memset ( server, 0, sizeof ( server ) );

	for ( auto i: data ){
		int ans = 0;

		for ( int j = 1 ; j <= n && i.k ; j++ ){
			if ( server[j] > i.t )
				continue;

			ans += j;
			server[j] = i.t + i.d;
			i.k--;
		}

		if ( i.k )
			ans = -1;

		cout << ans << '\n';
	}
}