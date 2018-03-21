#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bit[10005], n;

inline ll sum ( int i ){
	ll re = 0;
	while ( i ){
		re += bit[i];
		i -= i & -i;
	}

	return re;
}

inline void add ( int i, int value ){
	while ( i <= n ){
		bit[i] += value;
		i += i & -i;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	ll ans, stop, s[100005];
	vector < int > data;
	while ( cin >> n ){
		// cout << 111 << '\n';

		if ( !n )
			break;

		if ( !data.empty() )
			data.clear();
		memset ( bit, 0, sizeof ( bit ) );
		ans = -1;

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.push_back ( stop );
		}

		// cout << 222 << '\n';

		sort ( data.begin(), data.end() );

		s[0] = data[0];
		for ( int i = 1 ; i < n ; i++ )
			s[i] = s[i - 1] + data[i];

		// cout << 333 << '\n';

		for ( int i = n - 1 ; i > 1 ; i-- )
			if ( data[i] <= s[i - 1] ){
				ans = i + 1;
				break;
			}

		if ( ans != -1 )
			cout << ans;
		else if ( data[0] == data[1] )
			cout << 2;
		else
			cout << 0;
		cout << '\n';
	}
}