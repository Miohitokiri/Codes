#include<bits/stdc++.h>

using namespace std;

int n, m;
vector < int > data;

inline bool test ( int d ){
	int last = 0;
	for ( int i = 1 ; i < m ; i++ ){
		int crt = last + 1;

		while ( crt < n && data[crt] - data[last] < d )
			crt++;

		if ( crt == n )
			return false;

		last = crt;
	}

	return true;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int l, r, stop, mid;
	while ( cin >> n >> m ){
		if ( !n && !m )
			break;

		data.clear();
		l = 0, r = n - 1;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.push_back ( stop );
		}

		sort ( data.begin(), data.end() );

		while ( r - l > 1 ){
			mid = ( l + r ) / 2;
			if ( test ( mid ) )
				l = mid;
			else
				r = mid;
		}

		cout << mid << '\n';
	}
}