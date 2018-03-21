#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int change ( string str ){
	int res = 0;
	for ( auto i: str ){
		res *= 10;
		res += ( int ) i - '0';
	}

	return res;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	string str = "11";
	vector < int > data;
	set < string > sstr, tmp;
	sstr.insert ( "" );
	while ( sstr.size() <= 1000005 ){
		for ( auto i: sstr )
			for ( char j = '0' ; j <= '9' ; j++ )
				tmp.insert ( j + i + j );

		for ( auto i: tmp )
			sstr.insert ( i );
		tmp.clear();
	}

	// cout << sstr.size() << '\n'; // del

	for ( auto i: sstr ){
		if ( i[0] == '0' )
			continue;
		data.push_back ( change ( i ) );
	}

	sort ( data.begin(), data.end() );

	int n, k, res = 0;
	cin >> n >> k;
	for ( int i = 0 ; i <= n ; i++ ){
		res += data[i];
		res %= k;
	}
	cout << res << '\n';
}