#include<bits/stdc++.h>

using namespace std;

bool cmp ( pair < int, int > a, pair < int, int > b ) {
	if ( a.first == b.first )
		return a.second < b.second;
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, a, b, w, c, stop, l, r, mid;
	pair < int, int > data[100005];
	int ans;

	while ( cin >> n >> a >> b ){
		ans = 1e9;
		memset ( data, 0, sizeof ( data ) );
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i].first >> data[i].second;

		if ( a == b ){
			cout << 0 << '\n';
			continue;
		}

		else{
			sort ( data, data + n );

			for ( int i = 0 ; i < n ; i++ )
				if ( data[i].first * a % b == 0 ) {
					int x = data[i].first * a / b;
					pair < int, int > y = *lower_bound ( data, data + n, make_pair ( x, 0 ), cmp );
					if ( y.first == x )
						ans = min ( ans, data[i].second + y.second );
			}
		}

		if ( ans == 1e9 )
			cout << -1;
		else
			cout << ans;
		cout << '\n';
	}
}