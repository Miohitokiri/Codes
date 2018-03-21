#include<bits/stdc++.h>

using namespace std;

int BIT[1000005], n;

inline int sum ( int n ){
	int s = 0;
	while ( n ){
		s += BIT[n];
		n -= n & -n;
	}
	return s;
}

inline void add ( int i, int x ){
	while ( i <= n ){
		BIT[i] += x;
		i += i & -i;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int stop, ans;
	while ( cin >> n ){
		if ( !n )
			break;

		memset ( BIT, 0, sizeof ( BIT ) );
		ans = 0;

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			ans += i - sum ( stop );
			add ( stop, 1 );
		}

		cout << ans << '\n';
	}
}