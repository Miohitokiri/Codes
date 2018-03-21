#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	vector < int > data;
	int n, m;
	cin >> n;
	while ( n-- ){
		cin >> m;
		data.push_back ( m );
	}

	sort ( data.begin(), data.end() );

	cin >> m;
	while ( m-- ){
		cin >> n;
		cout << upper_bound ( data.begin(), data.end(), n ) - lower_bound ( data.begin(), data.end(), n ) << '\n';
	}
}