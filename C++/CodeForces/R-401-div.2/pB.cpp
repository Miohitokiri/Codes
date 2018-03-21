#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, hit = 0, beHit = 0;
	string s;
	vector < int > sherlock;
	multiset < int > moriarty;
	cin >> n >> s;
	for ( auto i: s )
		sherlock.push_back ( ( int ) i - '0' );

	cin >> s;
	for( auto i: s )
		moriarty.insert ( ( int ) i - '0' );

	sort ( sherlock.begin(), sherlock.end() );

	for ( auto i: sherlock ){
		multiset < int >::iterator x = moriarty.upper_bound ( i );
		if ( x != moriarty.end() ){
			beHit++;
			moriarty.erase ( x );
		}
	}

	moriarty.clear();

	for ( auto i: s )
		moriarty.insert ( ( int ) i - '0' );

	for ( auto i: sherlock ){
		multiset < int >::iterator x = moriarty.lower_bound ( i );
		if ( x != moriarty.end() )
			moriarty.erase ( x );
		else
			hit++;
	}

	cout << hit << '\n' << beHit << '\n';
}