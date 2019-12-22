#include<bits/stdc++.h>
using namespace std;

map < int, int > liba, libb;
int m;

inline bool solve ( vector < pair < int, int > > a, vector < pair < int, int > > b ){
	int sz = a.size(), swp = ( b[0].first + m - a[0].first ) % m;
	for ( int i = 0 ; i < sz ; i++ ){
		if ( a[i].second != b[i].second || swp != ( b[i].first + m - a[i].first ) % m )
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	vector < int > a, b;
	int n, swp;
	bool flag = true;
	cin >> n >> m;
	a.resize ( n );
	b.resize ( n );
	for ( auto &i: a )
		cin >> i;
	for ( auto &i: b )
		cin >> i;
	sort ( a.begin(), a.end() );
	sort ( b.begin(), b.end() );
	for ( int i = 0 ; i < n ; i++ ){
		if ( a[i] != b[i] ){
			flag = false;
			break;
		}
	}
	if ( flag ){
		cout << "0\n";
		return 0;
	}
	for ( int i = 0 ; i < n ; i++ ){
		liba[a[i]]++;
		libb[b[i]]++;
	}
	vector < pair < int, int > > dataa, datab;
	for ( auto i: liba ){
		dataa.push_back ( make_pair ( i.first, i.second ) );
	}
	for ( auto i: libb ){
		datab.push_back ( make_pair ( i.first, i.second ) );
	}
	if ( dataa.size() == 1 ){
		cout << ( datab[0].first + m - dataa[0].first ) % m << '\n';
		return 0;
	}
	for ( int i = 0 ; i < n ; i++ ){
		if ( solve ( dataa, datab ) ){
			cout << ( datab[0].first + m - dataa[0].first ) % m << '\n';
			return 0;
		}
		dataa.insert ( dataa.begin(), dataa.back() );
		dataa.pop_back();
	}
}