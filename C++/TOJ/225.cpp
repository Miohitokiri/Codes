#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, a, b, now, l;
	cin >> n;
	vector < pair < int, int > > data;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> a >> b;
		data.push_back ( make_pair ( a, b ) );
	}

	now = data[0].y;
	l = n;

	for ( int i = 0 ; i < n ; i++ ){
		if ( now < data[i].y ){
			l = i;
			break;
		}
		now = max ( now, data[i].y + data[i].x );
	}

	// cout << ( ans ? "hurray" : now ) << '\n';

	if ( l == n )
		cout << "hurray";
	else
		cout << n - l;
	puts ( "" );
}