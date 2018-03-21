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
	while ( sstr.size() <= 10005 ){
		for ( auto i: sstr ){
			for ( char j = '1' ; j <= '9' ; j++ ){
				str = "";
				str += j;
				str += i;
				str += j;
				tmp.insert ( str );
			}
		}

		for ( auto i: tmp )
			sstr.insert ( i );
		tmp.clear();
	}

	for ( auto i: sstr )
		data.push_back ( change ( i ) );

	sort ( data.begin(), data.end() );

	int n, k, res = 0;
	cin >> n >> k;
	for ( int i = 0 ; i < n ; i++ ){
		res += data[i];
		res %= k;
	}

	cout << res << '\n';
}