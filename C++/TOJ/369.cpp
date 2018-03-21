#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	vector < int > data, dp;
	map < int, int > s;
	while ( cin >> n ){
		data.clear(), s.clear(), dp.clear();
		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			s[stop] = i;
		}

		for ( int i = 0 ; i < n ; i++ ){
			cin >> stop;
			data.push_back ( s[stop] );
		}

		for ( int i: data ){
			if ( dp.empty() || dp.back() < i )
				dp.push_back ( i );
			else
				*lower_bound ( dp.begin(), dp.end(), i ) = i;
		}

		cout << dp.size() << '\n';
	}
}