#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

#define int long long

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, mi = 10000005, a, b;
	vector < pair < int, int > > m;
	cin >> n;
	double data = sqrt ( n );
	if ( data == ( int ) data )
		a = b = ( int ) data;
	else{
		for ( int i = 1 ; i <= n ; i++ ){
			data = ( double ) n / i;
			if ( data == ( int ) data )
				m.push_back ( make_pair ( i, data ) );
		}

		for ( auto i: m )
			if ( fabs ( i.x - i.y ) < mi ){
				mi = fabs ( i.x - i.y );
				a = i.x, b = i.y;
			}

		if ( a > b )
			swap ( a, b );
	}

	cout << a << ' ' << b << '\n';
}