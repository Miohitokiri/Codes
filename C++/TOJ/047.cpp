#include<bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	set < int > check;
	vector < int > data;
	int n, t;
	cin >> n;
	while ( n-- ){
		cin >> t;
		if ( check.find ( t ) == check.end() ){
			check.insert ( t );
			data.push_back ( t );
		}
	}

	sort ( data.begin(), data.end() );

	cin >> t;
	while ( t-- ){
		cin >> n;
		auto i = lower_bound ( data.begin(), data.end(), n );

		if ( *i == n )
			cout << n;
		else if ( n < *data.begin() )
			cout << "no " << *i;
		else if ( *data.rbegin() < n )
			cout << *data.rbegin() << " no";
		else{
			i--;
			cout << *i << ' ';
			i++;
			cout << *i;
		}
		cout << '\n';
	}
}